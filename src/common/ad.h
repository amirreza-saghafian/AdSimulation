//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef DEMO_AD_H
#define DEMO_AD_H

#include "item.h"
#include <string>

class Ad {
 public:

  std::string id_;
  Item item_;  // item_ advertised in the ad
  std::string company_;  // company_ that sells the item_
};

#endif //DEMO_AD_H
