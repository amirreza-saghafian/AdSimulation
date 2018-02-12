//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "test_items.h"
#include "src/tool/load_data.h"
#include "src/analysis/user_analysis.h"

#include <random>

int TestUserCache() {
  // gets number of users
  auto num_users = GetInput<size_t>("Enter number of users: ");
  // gets number of ads to send
  auto num_ads_to_send = GetInput<size_t>("Enter number of ads to send: ");

  // loads items from the file and builds ad instances
  std::vector<Item> items = LoadItems();
  std::vector<Ad> ads = BuildAds(items);
  std::vector<User> users = BuildUsers(num_users);
  SendAdToUsers(&users, ads, num_ads_to_send);
  Report(users, num_ads_to_send);

  return 0;
}

std::vector<Item> LoadItems() {
  // load items from the file
  LoadData load;
  std::string item_file = "../test/data/items.txt";
  return load.LoadItems(item_file);
}

// Create one ad for each item_
std::vector<Ad> BuildAds(const std::vector<Item>& items) {
  std::vector<Ad> ads;
  size_t i = 1;

  for (auto& item : items) {
    ads.emplace_back(Ad{"ad" + std::to_string(i++), item,
                        "company_" + std::to_string(i++)});
  }

  return ads;
}

std::vector<User> BuildUsers(const size_t num_users) {
  std::vector<User> users(num_users);
  size_t i = 1;

  // set the user ids
  for (auto& user : users) {
    user.SetId("user" + std::to_string(i++));
  }

  return users;
}

void SendAdToUsers(std::vector<User>* users_ptr, std::vector<Ad>& ads,
                   long num_ads_to_send) {
  auto& users = *users_ptr;

  // build some random number generators to "simulate" user behavior
  // This is very fictional and unrealistic model to test the system
  std::random_device r;  // for seed generation
  std::mt19937 gen(r());  // using mersenne twister
  std::uniform_real_distribution<double> real_dist(0, 1.0);
  std::uniform_int_distribution<size_t> int_user_dist(0, users.size() - 1);
  std::uniform_int_distribution<size_t> int_ad_dist(0, ads.size() - 1);

  // 5% chance that a user clicks an ad
  double click_probability = 0.05;
  // 1% chance that the user will buy an ad that has been clicked
  double purchase_probability = 0.01;

  for (size_t j = 0; j < num_ads_to_send; ++j) {
    // randomly choose a user to send an ad to
    size_t user_index = int_user_dist(gen);
    // randomly choose an ad
    size_t ad_index = int_ad_dist(gen);
//    std::cout << ads[ad_index].id_ << " has been sent to "
//              << users[user_index].GetId() << std::endl;

    // add this ad to the users cache of sent ads
    users[user_index].InsertSentAd(&ads[ad_index]);

    // probability that the user click on the ad
    if (real_dist(gen) < click_probability) {
//      std::cout << users[user_index].GetId() << " has clicked on ad "
//                << ads[ad_index].id_;

      // add this ad to the cache of clicked ads
      users[user_index].InsertClickedAd(&ads[ad_index]);

      // chance that user will purchase the item_
      if (real_dist(gen) < purchase_probability) {
        users[user_index].InsertPurchased(&ads[ad_index].item_);
//        std::cout << users[user_index].GetId() << " has purchased item "
//                  << ads[ad_index].item_.name_ << std::endl;
//        std::cout << ", and purchased_ the item_" << std::endl;
      } else {
//        std::cout << ", but did NOT purchase the item_" << std::endl;
//        std::cout << std::endl;
      }
    }
  }
}

void Report(const std::vector<User>& users, const size_t num_ads_to_send) {
  double sum = 0.0;

  for (const auto& user : users) {
    double total_purchase = user.TotalPricePurchased();
    sum += total_purchase;
//    if (total_purchase > 0) std::cout << total_purchase << std::endl;
  }

  UserAnalysis user_analysis(users);
  double total_revenue = user_analysis.ComputeTotalRevenue();

//  double total_revenue = std::accumulate(users.begin(), users.end(), 0,
//                                               [&](double sum, const User& u)
//                                               { return sum +
//                                                   (u.TotalPricePurchased());
//                                               });
  std::cout << "total revenue: " << total_revenue << std::endl;

  std::unordered_map<Item*, size_t> num_items_sold =
      user_analysis.NumEachItemSold();

  for (const auto& it : num_items_sold) {
    std::cout << "Item " << it.first->name_ << " has been purchased "
              << it.second << " times!" << std::endl;
  }
}