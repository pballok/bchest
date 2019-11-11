#ifndef BCHEST_CORE_SECONDARYATTRIBUTE_H
#define BCHEST_CORE_SECONDARYATTRIBUTE_H

#include "CharacterAttribute.h"

#include <array>
#include <memory>

class SecondaryAttribute : public CharacterAttribute
{
public:
    SecondaryAttribute(int modifier_cost, std::shared_ptr<CharacterAttribute> base_attribute);
    SecondaryAttribute(const SecondaryAttribute& other) = delete;
    SecondaryAttribute(SecondaryAttribute&& other) = delete;
    SecondaryAttribute& operator=(const SecondaryAttribute& other) = delete;
    SecondaryAttribute& operator=(SecondaryAttribute&& other) = delete;
    virtual ~SecondaryAttribute() = default;

    double value() const override;

protected:
    std::shared_ptr<CharacterAttribute> base_attribute_;
};

#endif // BCHEST_CORE_SECONDARYATTRIBUTE_H
