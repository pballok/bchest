#include "BaseAttribute.h"

BaseAttribute::BaseAttribute(double modifier_cost)
  : modifier_(0.0),
    modifier_cost_(modifier_cost)
{
}

void BaseAttribute::set_modifier(double modifier)
{
  modifier_ = modifier;
}

int BaseAttribute::cost() const
{
  return static_cast<int>(modifier_ * modifier_cost_);
}
