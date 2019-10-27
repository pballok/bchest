#include "SecondaryAttribute.h"

template<std::size_t N>
SecondaryAttribute<N>::SecondaryAttribute(int modifier_cost, std::array<std::shared_ptr<BaseAttribute>, N> base_attributes)
  : BaseAttribute(modifier_cost),
    base_attributes_(base_attributes)
{
}

template<std::size_t N>
double SecondaryAttribute<N>::value() const {
  return base_attributes_[0]->value() + modifier_;
}
