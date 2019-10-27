#ifndef BCHEST_CORE_FIXED_ATTRIBUTE_H
#define BCHEST_CORE_FIXED_ATTRIBUTE_H

#include "BaseAttribute.h"

class FixedAttribute : public BaseAttribute
{
public:
    FixedAttribute(double base);
    FixedAttribute(const FixedAttribute& other) = delete;
    FixedAttribute(FixedAttribute&& other) = delete;
    FixedAttribute& operator=(const FixedAttribute& other) = delete;
    FixedAttribute& operator=(FixedAttribute&& other) = delete;
    virtual ~FixedAttribute() = default;

    double value() const override;

private:
    double base_;
};

#endif // BCHEST_CORE_FIXED_ATTRIBUTE_H
