//
// Created by Amirreza Saghafian on 2/11/18.
// User class
//
//

#ifndef ADSIMULATION_USER_H
#define ADSIMULATION_USER_H

#include "item.h"
#include "ad.h"
#include "src/container/lru_cache.h"

#include <vector>
#include <string>

class User {
 public:

  explicit User(const std::string& user_id = "none", size_t capacity = 100);
  void InsertSentAd(Ad* ad);
  void InsertClickedAd(Ad* ad);
  void InsertPurchased(Item* item);
  void PrintAdSent() const;
  void PrintAdClicked() const;
  void PrintPurchased() const;
  void SetCacheCapacity(size_t capacity);
  size_t GetCacheCapacity() const;
  void SetId(const std::string& user_id);
  std::string GetId() const;
  void SetOutputWidth(int width);
  double TotalPricePurchased() const;
  std::unordered_map<Item*, size_t> GetNumItemsPurchased() const;

 private:

  std::vector<Item*> purchased_;  // vector of the items purchased_ so far
  LruCache<std::string, Ad*> ads_clicked_;  // cache of ads clicked by user
  LruCache<std::string, Ad*> ads_sent_;  // cache of ads send to user

  size_t cache_capacity_;  // number of ads to record in cache
  std::string id_;  // user ID
  int output_width_;  // control width of io output
};

#endif //ADSIMULATION_USER_H
