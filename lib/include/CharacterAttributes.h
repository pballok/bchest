#ifndef BCHEST_CORE_CHARACTER_ATTRIBUTES_H
#define BCHEST_CORE_CHARACTER_ATTRIBUTES_H

#include "PrimaryAttribute.h"
#include "SecondaryAttribute.h"

#include <cmath>
#include <memory>

class AttributeST : public PrimaryAttribute
{
public:
  AttributeST() : PrimaryAttribute(10, 10) {}
};

class AttributeIQ : public PrimaryAttribute
{
public:
  AttributeIQ() : PrimaryAttribute(20, 10) {}
};

class AttributeDX : public PrimaryAttribute
{
public:
  AttributeDX() : PrimaryAttribute(20, 10) {}
};

class AttributeHT : public PrimaryAttribute
{
public:
  AttributeHT() : PrimaryAttribute(10, 10) {}
};

class AttributeHP : public SecondaryAttribute
{
public:
  AttributeHP(std::shared_ptr<CharacterAttribute> attribute_st) : SecondaryAttribute(2, attribute_st) {}
};

class AttributeWill : public SecondaryAttribute
{
public:
  AttributeWill(std::shared_ptr<CharacterAttribute> attribute_iq) : SecondaryAttribute(5, attribute_iq) {}
};

class AttributePer : public SecondaryAttribute
{
public:
  AttributePer(std::shared_ptr<CharacterAttribute> attribute_iq) : SecondaryAttribute(5, attribute_iq) {}
};

class AttributeFP : public SecondaryAttribute
{
public:
  AttributeFP(std::shared_ptr<CharacterAttribute> attribute_ht) : SecondaryAttribute(3, attribute_ht) {}
};

class AttributeBS : public CharacterAttribute
{
public:
  AttributeBS(std::shared_ptr<CharacterAttribute> attribute_ht, std::shared_ptr<CharacterAttribute> attribute_dx) : CharacterAttribute(20), ht_base_(attribute_ht), dx_base_(attribute_dx) {}
  double value() const override { return ((ht_base_->value() + dx_base_->value()) / 4.0) + modifier_; }
protected:
  std::shared_ptr<CharacterAttribute> ht_base_;
  std::shared_ptr<CharacterAttribute> dx_base_;
};

class AttributeBM : public CharacterAttribute
{
public:
  AttributeBM(std::shared_ptr<CharacterAttribute> attribute_bs) : CharacterAttribute(5), bs_base_(attribute_bs) {}
  double value() const override { return floor(bs_base_->value()) + modifier_; }
protected:
  std::shared_ptr<CharacterAttribute> bs_base_;
};

#endif // BCHEST_CORE_CHARACTER_ATTRIBUTES_H
