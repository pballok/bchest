#include "Character.h"
#include "CharacterAttributes.h"

Character::Character(std::string name)
  : name_(std::move(name))
{
  attributes_[CharacterAttributeType::ST] = std::make_shared<AttributeST>();
  attributes_[CharacterAttributeType::IQ] = std::make_shared<AttributeIQ>();
  attributes_[CharacterAttributeType::DX] = std::make_shared<AttributeDX>();
  attributes_[CharacterAttributeType::HT] = std::make_shared<AttributeHT>();
  attributes_[CharacterAttributeType::HP] = std::make_shared<AttributeHP>(attributes_.at(CharacterAttributeType::ST));
  attributes_[CharacterAttributeType::WILL] = std::make_shared<AttributeWill>(attributes_.at(CharacterAttributeType::IQ));
  attributes_[CharacterAttributeType::PER] = std::make_shared<AttributePer>(attributes_.at(CharacterAttributeType::IQ));
  attributes_[CharacterAttributeType::FP] = std::make_shared<AttributeFP>(attributes_.at(CharacterAttributeType::HT));
  attributes_[CharacterAttributeType::BS] = std::make_shared<AttributeBS>(attributes_.at(CharacterAttributeType::DX), attributes_.at(CharacterAttributeType::HT));
  attributes_[CharacterAttributeType::BM] = std::make_shared<AttributeBM>(attributes_.at(CharacterAttributeType::BS));
}

std::string Character::name() const
{
  return name_;
}

double Character::cost() const
{
  double cost = 0.0;
  for(const auto& attrib : attributes_) {
    cost += attrib.second->cost();
  }

  return cost;
}

double Character::attribute_value(CharacterAttributeType attribute) const
{
  return attributes_.at(attribute)->value();
}

double Character::attribute_modifier(CharacterAttributeType attribute) const
{
  return attributes_.at(attribute)->modifier();
}

void Character::set_attribute_modifier(CharacterAttributeType attribute, double modifier)
{
  attributes_.at(attribute)->set_modifier(modifier);
}

double Character::attribute_cost(CharacterAttributeType attribute) const
{
  return attributes_.at(attribute)->cost();
}
