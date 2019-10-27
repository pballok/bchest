#ifndef BCHEST_CORE_CHARACTER_H
#define BCHEST_CORE_CHARACTER_H

#include <map>
#include <string>

#include "CharacterAttributeType.h"

class BaseAttribute;

class Character
{
public:
    Character(std::string name);
    Character(const Character& other) = delete;
    Character(Character&& other) = delete;
    Character& operator=(const Character& other) = delete;
    Character& operator=(Character&& other) = delete;
    virtual ~Character() = default;

    std::string name() const;
    double cost() const;

    double attribute_value(CharacterAttributeType attribute) const;
    double attribute_modifier(CharacterAttributeType attribute) const;
    void set_attribute_modifier(CharacterAttributeType attribute, double modifier);
    double attribute_cost(CharacterAttributeType attribute) const;

private:
    std::string name_;
    std::map<CharacterAttributeType, std::shared_ptr<BaseAttribute>> attributes_;
};

#endif // BCHEST_CORE_CHARACTER_H
