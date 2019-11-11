#include "CharacterAttribute.h"

CharacterAttribute::CharacterAttribute(double modifier_cost)
  : modifier_(0.0),
    modifier_cost_(modifier_cost)
{
}

void CharacterAttribute::set_modifier(double modifier)
{
  modifier_ = modifier;
}

double CharacterAttribute::modifier() const
{
  return modifier_;
}

int CharacterAttribute::cost() const
{
  return static_cast<int>(modifier_ * modifier_cost_);
}
