//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef DEMO_ITEM_H
#define DEMO_ITEM_H

#include <string>

class Item {
 public:

  std::string name_;  // name_ of the item_
  std::string maker_id_;  // company_ that makes the item_
  double price_;  // price_ of the item_

  bool operator==(const Item& that) const;
  bool operator!=(const Item& that) const;
};

#endif //DEMO_ITEM_H
