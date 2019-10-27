#ifndef BCHEST_CORE_SECONDARY_ATTRIBUTE_H
#define BCHEST_CORE_SECONDARY_ATTRIBUTE_H

#include "BaseAttribute.h"

#include <array>
#include <memory>

template<std::size_t N>
class SecondaryAttribute : public BaseAttribute
{
public:
    SecondaryAttribute(int modifier_cost, std::array<std::shared_ptr<BaseAttribute>, N> base_attributes);
    SecondaryAttribute(const SecondaryAttribute& other) = delete;
    SecondaryAttribute(SecondaryAttribute&& other) = delete;
    SecondaryAttribute& operator=(const SecondaryAttribute& other) = delete;
    SecondaryAttribute& operator=(SecondaryAttribute&& other) = delete;
    virtual ~SecondaryAttribute() = default;

    double value() const override;

protected:
    std::array<std::shared_ptr<BaseAttribute>, N> base_attributes_;
};

#endif // BCHEST_CORE_SECONDARY_ATTRIBUTE_H
