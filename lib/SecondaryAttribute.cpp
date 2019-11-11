#include "SecondaryAttribute.h"

SecondaryAttribute::SecondaryAttribute(int modifier_cost, std::shared_ptr<CharacterAttribute> base_attribute)
  : CharacterAttribute(modifier_cost),
    base_attribute_(base_attribute)
{
}

double SecondaryAttribute::value() const {
  return base_attribute_->value() + modifier_;
}
