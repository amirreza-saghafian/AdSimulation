//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef DEMO_AD_WITH_ACTION_H
#define DEMO_AD_WITH_ACTION_H

#include "ad.h"
#include "src/action/action_strategy.h"

class AdWithAction : public Ad {
 public:

  explicit AdWithAction(ActionStrategy* action);
  void Action(const std::string& file) const;

 private:

  ActionStrategy* action_;
};

#endif //DEMO_AD_WITH_ACTION_H
