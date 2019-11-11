#include "PrimaryAttribute.h"

PrimaryAttribute::PrimaryAttribute(int modifier_cost, double base)
  : CharacterAttribute(modifier_cost),
    base_(base)
{
}

double PrimaryAttribute::value() const {
    return base_ + modifier_;
}
