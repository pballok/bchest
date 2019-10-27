#include "Character.h"
#include "CharacterAttributes.h"

Character::Character(std::string name)
  : name_(std::move(name))
{
  auto attribute_st   = std::make_shared<AttributeST>();
  auto attribute_iq   = std::make_shared<AttributeIQ>();
  auto attribute_dx   = std::make_shared<AttributeDX>();
  auto attribute_ht   = std::make_shared<AttributeHT>();
  auto attribute_hp   = std::make_shared<AttributeHP>(attribute_st);
  auto attribute_will = std::make_shared<AttributeWill>(attribute_iq);
  auto attribute_per  = std::make_shared<AttributePer>(attribute_iq);
  auto attribute_fp   = std::make_shared<AttributeFP>(attribute_ht);
  auto attribute_bs   = std::make_shared<AttributeBS>(attribute_ht, attribute_dx);
  auto attribute_bm   = std::make_shared<AttributeBM>(attribute_bs);

  attributes_[CharacterAttributeType::ST] = attribute_st;
  attributes_[CharacterAttributeType::IQ] = attribute_iq;
  attributes_[CharacterAttributeType::DX] = attribute_dx;
  attributes_[CharacterAttributeType::HT] = attribute_ht;
  attributes_[CharacterAttributeType::HP] = attribute_hp;
  attributes_[CharacterAttributeType::WILL] = attribute_will;
  attributes_[CharacterAttributeType::PER] = attribute_per;
  attributes_[CharacterAttributeType::FP] = attribute_fp;
  attributes_[CharacterAttributeType::BS] = attribute_bs;
  attributes_[CharacterAttributeType::BM] = attribute_bm;
}

std::string Character::name() const
{
  return name_;
}

double Character::cost() const
{
  double cost = 0.0;
  for(auto attrib : attributes_) {
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
