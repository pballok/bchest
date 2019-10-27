#include "FixedAttribute.h"

FixedAttribute::FixedAttribute(int modifier_cost, double base)
  : BaseAttribute(modifier_cost),
    base_(base)
{
}

double FixedAttribute::value() const {
    return base_ + modifier_;
}
