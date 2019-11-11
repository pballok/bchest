#ifndef BCHEST_CORE_CHARACTERATTRIBUTE_H
#define BCHEST_CORE_CHARACTERATTRIBUTE_H

class CharacterAttribute
{
public:
    explicit CharacterAttribute(double modifier_cost);
    CharacterAttribute(const CharacterAttribute& other) = delete;
    CharacterAttribute(CharacterAttribute&& other) = delete;
    CharacterAttribute& operator=(const CharacterAttribute& other) = delete;
    CharacterAttribute& operator=(CharacterAttribute&& other) = delete;
    virtual ~CharacterAttribute() = default;

    void set_modifier(double modifier);
    double modifier() const;

    virtual double value() const = 0;

    int cost() const;

protected:
    double modifier_;
    double modifier_cost_;
};

#endif // BCHEST_CORE_CHARACTERATTRIBUTE_H
