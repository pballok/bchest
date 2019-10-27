#include "FixedAttribute.h"

FixedAttribute::FixedAttribute(double base) : BaseAttribute(), base_(base)
{
}

double FixedAttribute::value() const {
    return base_;
}