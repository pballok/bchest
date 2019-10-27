#include "BasicAttribute.h"

BasicAttribute::BasicAttribute(int modifier_cost, double base)
  : BaseAttribute(modifier_cost),
    base_(base)
{
}

double BasicAttribute::value() const {
    return base_ + modifier_;
}
