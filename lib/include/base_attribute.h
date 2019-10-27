#ifndef BCHEST_CORE_BASE_ATTRIBUTE_H
#define BCHEST_CORE_BASE_ATTRIBUTE_H

class BaseAttribute
{
    BaseAttribute();
    BaseAttribute(const BaseAttribute& other) = delete;
    BaseAttribute(BaseAttribute&& other) = delete;
    BaseAttribute& operator=(const BaseAttribute& other) = delete;
    BaseAttribute& operator=(BaseAttribute&& other) = delete;
    virtual ~BaseAttribute() = default;
};

#endif // BCHEST_CORE_BASE_ATTRIBUTE_H
