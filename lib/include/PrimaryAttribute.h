#ifndef BCHEST_CORE_PRIMARYATTRIBUTE_H
#define BCHEST_CORE_PRIMARYATTRIBUTE_H

#include "CharacterAttribute.h"

class PrimaryAttribute : public CharacterAttribute
{
public:
    PrimaryAttribute(int modifier_cost, double base);
    PrimaryAttribute(const PrimaryAttribute& other) = delete;
    PrimaryAttribute(PrimaryAttribute&& other) = delete;
    PrimaryAttribute& operator=(const PrimaryAttribute& other) = delete;
    PrimaryAttribute& operator=(PrimaryAttribute&& other) = delete;
    virtual ~PrimaryAttribute() = default;

    double value() const override;

private:
    double base_;
};

#endif // BCHEST_CORE_PRIMARYATTRIBUTE_H
