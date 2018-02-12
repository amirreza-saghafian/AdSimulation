//
// Created by Amirreza Saghafian on 2/11/18.
// This is derived action_ subclass using strategy design pattern.
// Will only display the file.
// More advanced subclassed can e.g. show an image or a movie.
// Using strategy design pattern we can create different classes using
// composition over inheritance principle.
//

#ifndef DEMO_TEXT_ACTION_STRATEGY_H
#define DEMO_TEXT_ACTION_STRATEGY_H

#include "action_strategy.h"

class TextActionStrategy : public ActionStrategy {
  void Action(const std::string& file) override;
};

#endif //DEMO_TEXT_ACTION_STRATEGY_H
