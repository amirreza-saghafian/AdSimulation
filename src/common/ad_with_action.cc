//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "ad_with_action.h"

AdWithAction::AdWithAction(ActionStrategy* action) {
  this->action_ = action;
}

void AdWithAction::Action(const std::string& file) const {
  action_->Action(file);
}