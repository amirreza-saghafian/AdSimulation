//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "user_analysis.h"

#include <numeric>

UserAnalysis::UserAnalysis(const std::vector<User>& users_vec) :
    users(users_vec) {}

double UserAnalysis::ComputeTotalRevenue() const {
  return std::accumulate(users.begin(), users.end(), 0,
                         [&](double sum, const User& u) {
                           return sum + (u.TotalPricePurchased());
                         });
}

std::unordered_map<Item*, size_t> UserAnalysis::NumEachItemSold() const {
  // a hash table that maps Item to the number of sold units
  std::unordered_map<Item*, size_t> num_items_sold;

  for (const auto& user : users) {
    // get the number of items that this user has purchased
    std::unordered_map<Item*, size_t> user_num_items_purchased =
        user.GetNumItemsPurchased();

    for (const auto& it : user_num_items_purchased) {
      // if the item is already in the hash table (i.e. a user has bought it
      // before) increments the counter by 1; otherwise, sets the counter to 1
      if (num_items_sold.find(it.first) != num_items_sold.end()) {
        num_items_sold[it.first] += 1;
      } else {
        num_items_sold[it.first] = 1;
      }
    }
  }

  return num_items_sold;
}