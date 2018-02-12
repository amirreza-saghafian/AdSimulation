//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef ADSIMULATION_USER_ANALYSIS_H
#define ADSIMULATION_USER_ANALYSIS_H

#include "src/common/user.h"
#include "src/common/item.h"
#include "src/common/ad.h"

#include <vector>

class UserAnalysis {
 public:

  explicit UserAnalysis(const std::vector<User>& users_vec);

  double ComputeTotalRevenue() const;
  // Number of units that each item has been purchased
  std::unordered_map<Item*, size_t> NumEachItemSold() const;

 private:
  const std::vector<User>& users;
};

#endif //ADSIMULATION_USER_ANALYSIS_H
