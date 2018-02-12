//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "user.h"

#include <iostream>
#include <iomanip>
#include <numeric>

User::User(const std::string& user_d, const size_t capacity) :
    cache_capacity_(capacity),
    id_(user_d),
    output_width_(20) {
}

void User::InsertSentAd(Ad* const ad) {
  ads_sent_.Insert(ad->id_, ad);
}

void User::InsertClickedAd(Ad* const ad) {
  ads_clicked_.Insert(ad->id_, ad);
}

void User::InsertPurchased(Item* const item) {
  purchased_.emplace_back(item);
}

void User::SetCacheCapacity(const size_t capacity) {
  if (capacity <= 0) {
    throw std::invalid_argument("User::SetCacheCapacity(): "
                                    "capacity must be positive!");
  }

  cache_capacity_ = capacity;
}

size_t User::GetCacheCapacity() const {
  return cache_capacity_;
}

void User::SetId(const std::string& user_id) {
  id_ = user_id;
}

std::string User::GetId() const {
  return id_;
}

void User::SetOutputWidth(const int width) {
  if (width <= 0) {
    throw std::invalid_argument("User::SetOutputWidth(): "
                                    "output width must be positive!");
  }

  output_width_ = width;
}

void User::PrintPurchased() const {
  std::cout << "List of items purchased_ by user " << id_ << ":"
            << std::endl;
  std::cout << std::setw(output_width_) << "name_"
            << std::setw(output_width_) << "price_"
            << std::setw(output_width_) << "maker"
            << std::endl;
  std::cout << std::setw(output_width_) << "-----"
            << std::setw(output_width_) << "-----"
            << std::setw(output_width_) << "-----"
            << std::endl;

  for (const auto& item : purchased_) {
    std::cout << std::setw(output_width_) << item->name_
              << std::setw(output_width_) << item->price_
              << std::setw(output_width_) << item->maker_id_
              << std::endl;
  }
}

void User::PrintAdSent() const {
  if (ads_sent_.GetNumberOfItemsInCache() != 0) {
    std::cout << "List of ads sent to user " << id_ << ":" << std::endl;
    ads_sent_.Print();
  } else {
    std::cout << "No ads sent to user " << id_ << "!" << std::endl;
  }
}

void User::PrintAdClicked() const {
  if (ads_clicked_.GetNumberOfItemsInCache() != 0) {
    std::cout << "List of ads clicked by user " << id_ << ":" << std::endl;
    ads_clicked_.Print();
  } else {
    std::cout << "No ads clicked by user " << id_ << "!" << std::endl;
  }
}

double User::TotalPricePurchased() const {
  return std::accumulate(purchased_.begin(), purchased_.end(), 0.0,
                         [&](double sum, const Item* const item) {
                           return sum + item->price_;
                         });
}

std::unordered_map<Item*, size_t> User::GetNumItemsPurchased() const {
  std::unordered_map<Item*, size_t> num_purchased;

  for (const auto& p : purchased_) {
    if (num_purchased.find(p) != num_purchased.end()) {
      num_purchased[p] += 1;
    } else {
      num_purchased[p] = 1;
    }
  }

  return num_purchased;
};