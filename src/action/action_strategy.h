//
// Created by Amirreza Saghafian on 2/11/18.
//

#ifndef DEMO_ACTION_STRATEGY_H
#define DEMO_ACTION_STRATEGY_H

#include <string>

class ActionStrategy {
 public:

  virtual void Action(const std::string& file) = 0;
};

#endif //DEMO_ACTION_STRATEGY_H
