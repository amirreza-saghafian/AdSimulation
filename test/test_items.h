//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef DEMO_TEST_ITEMS_H
#define DEMO_TEST_ITEMS_H

#include "src/common/user.h"
#include "src/container/lru_cache.h"

#include <vector>
#include <iostream>

int TestUserCache();
std::vector<Item> LoadItems();
std::vector<Ad> BuildAds(const std::vector<Item>& items);
std::vector<User> BuildUsers(size_t num_users);
void SendAdToUsers(std::vector<User>* users_ptr, std::vector<Ad>& ads,
                   long num_ads_to_send = 100);
void Report(const std::vector<User>& users, size_t num_ads_to_send);

template <class T>
T GetInput(const std::string&& message) {
  T output;
  std::cout << message;
  std::cin >> output;
  return output;
}

#endif //DEMO_TEST_ITEMS_H
