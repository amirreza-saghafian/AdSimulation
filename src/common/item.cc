//
// Created by Amirreza Saghafian on 2/11/18.
//

#include "item.h"

bool Item::operator==(const Item& that) const {
  return name_ == that.name_ &&
      maker_id_ == that.maker_id_ &&
      price_ == that.price_;
}

bool Item::operator!=(const Item& that) const {
  return name_ != that.name_ ||
         maker_id_ != that.maker_id_ ||
         price_ != that.price_;
}