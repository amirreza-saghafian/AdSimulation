//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef DEMO_LOAD_DATA_H
#define DEMO_LOAD_DATA_H

#include "src/common/item.h"
#include "src/common/user.h"

#include <string>
#include <vector>

class LoadData {
 public:

  std::vector<Item> LoadItems(const std::string& item_file) const;
  std::vector<User> LoadUsers(const std::string& user_file) const;

 private:

  std::vector<std::vector<std::string>> LoadText(const std::string& file) const;
};

#endif //DEMO_LOAD_DATA_H
