#ifndef BCHEST_CORE_CHARACTER_ATTRIBUTES_H
#define BCHEST_CORE_CHARACTER_ATTRIBUTES_H

#include "BasicAttribute.h"
#include "SecondaryAttribute.h"

#include <cmath>

class AttributeST : public BasicAttribute
{
public:
  AttributeST()
    : BasicAttribute(10, 10)
  {}
};

class AttributeIQ : public BasicAttribute
{
public:
  AttributeIQ()
    : BasicAttribute(20, 10)
  {}
};

class AttributeDX : public BasicAttribute
{
public:
  AttributeDX()
    : BasicAttribute(20, 10)
  {}
};

class AttributeHT : public BasicAttribute
{
public:
  AttributeHT()
    : BasicAttribute(10, 10)
  {}
};

class AttributeHP : public SecondaryAttribute<1>
{
public:
  AttributeHP(std::shared_ptr<AttributeST> attribute_st)
    : SecondaryAttribute(2, { attribute_st })
  {}
};

class AttributeWill : public SecondaryAttribute<1>
{
public:
  AttributeWill(std::shared_ptr<AttributeIQ> attribute_iq)
    : SecondaryAttribute(5, { attribute_iq })
  {}
};

class AttributePer : public SecondaryAttribute<1>
{
public:
  AttributePer(std::shared_ptr<AttributeIQ> attribute_iq)
    : SecondaryAttribute(5, { attribute_iq })
  {}
};

class AttributeFP : public SecondaryAttribute<1>
{
public:
  AttributeFP(std::shared_ptr<AttributeHT> attribute_ht)
    : SecondaryAttribute(3, { attribute_ht })
  {}
};

class AttributeBS : public SecondaryAttribute<2>
{
public:
  AttributeBS(std::shared_ptr<AttributeHT> attribute_ht, std::shared_ptr<AttributeDX> attribute_dx)
    : SecondaryAttribute(20, { attribute_ht, attribute_dx })
  {}

  double value() const override { return (base_attributes_[0]->value() + base_attributes_[1]->value()) / 4.0; }
};

class AttributeBM : public SecondaryAttribute<1>
{
  AttributeBM(std::shared_ptr<AttributeBS> attribute_bs)
    : SecondaryAttribute(5, { attribute_bs })
  {}

  double value() const override { return floor(base_attributes_[0]->value()) + modifier_; }
}

#endif // BCHEST_CORE_CHARACTER_ATTRIBUTES_H
