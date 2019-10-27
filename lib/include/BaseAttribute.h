#ifndef BCHEST_CORE_BASE_ATTRIBUTE_H
#define BCHEST_CORE_BASE_ATTRIBUTE_H

class BaseAttribute
{
public:
    explicit BaseAttribute(double modifier_cost);
    BaseAttribute(const BaseAttribute& other) = delete;
    BaseAttribute(BaseAttribute&& other) = delete;
    BaseAttribute& operator=(const BaseAttribute& other) = delete;
    BaseAttribute& operator=(BaseAttribute&& other) = delete;
    virtual ~BaseAttribute() = default;

    void set_modifier(double modifier);

    virtual double value() const = 0;

    int cost() const;

protected:
    double modifier_;
    double modifier_cost_;
};

#endif // BCHEST_CORE_BASE_ATTRIBUTE_H
