#ifndef BCHEST_CORE_BASIC_ATTRIBUTE_H
#define BCHEST_CORE_BASIC_ATTRIBUTE_H

#include "BaseAttribute.h"

class BasicAttribute : public BaseAttribute
{
public:
    BasicAttribute(int modifier_cost, double base);
    BasicAttribute(const BasicAttribute& other) = delete;
    BasicAttribute(BasicAttribute&& other) = delete;
    BasicAttribute& operator=(const BasicAttribute& other) = delete;
    BasicAttribute& operator=(BasicAttribute&& other) = delete;
    virtual ~BasicAttribute() = default;

    double value() const override;

private:
    double base_;
};

#endif // BCHEST_CORE_BASIC_ATTRIBUTE_H
