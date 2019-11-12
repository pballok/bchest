#include "Character.h"

#include "Character.h"

#include <catch2/catch.hpp>

SCENARIO("Default Attributes", "[Attributes]")
{
  GIVEN("a default-constructed Character") {
    Character character("Player");

    THEN("All attributes must be at their default values") {
      REQUIRE(character.attribute_value(CharacterAttributeType::ST) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::IQ) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::DX) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::HT) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::HP) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::WILL) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::PER) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::FP) == 10.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::BS) == 5.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::BM) == 5.0);
    }

    THEN("All costs must be 0") {
      REQUIRE(character.attribute_cost(CharacterAttributeType::ST) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::IQ) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::DX) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::HT) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::HP) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::WILL) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::PER) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::FP) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::BS) == 0.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::BM) == 0.0);
      REQUIRE(character.cost() == 0.0);
    }
  }
}

SCENARIO("Custom Attributes", "[Attributes]")
{
  GIVEN("a Character with modifiers ST:2, IQ:-1, DX:3, HT:-2, HP:1, Will:-1, Per:2, FP:3, BS:0.5, BM:1") {
    Character character("Player");
    character.set_attribute_modifier(CharacterAttributeType::ST, 2.0);
    character.set_attribute_modifier(CharacterAttributeType::IQ, -1.0);
    character.set_attribute_modifier(CharacterAttributeType::DX, 3.0);
    character.set_attribute_modifier(CharacterAttributeType::HT, -2.0);
    character.set_attribute_modifier(CharacterAttributeType::HP, 1.0);
    character.set_attribute_modifier(CharacterAttributeType::WILL, -1.0);
    character.set_attribute_modifier(CharacterAttributeType::PER, 2.0);
    character.set_attribute_modifier(CharacterAttributeType::FP, 3.0);
    character.set_attribute_modifier(CharacterAttributeType::BS, 0.5);
    character.set_attribute_modifier(CharacterAttributeType::BM, 1);

    THEN("Attribute values must be ST:12, IQ:9, DX:13 and HT:8, HP:13, Will:8, Per:11, FP:11, BS:5.75, BM:6") {
      REQUIRE(character.attribute_value(CharacterAttributeType::ST) == 12.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::IQ) == 9.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::DX) == 13.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::HT) == 8.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::HP) == 13.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::WILL) == 8.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::PER) == 11.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::FP) == 11.0);
      REQUIRE(character.attribute_value(CharacterAttributeType::BS) == 5.75);
      REQUIRE(character.attribute_value(CharacterAttributeType::BM) == 6);
    }

    THEN("Attribute costs must be ST:20, IQ:-20, DX:60, HT:-20, HP:2, Will:-5, Per:10, FP:9, BS:10, BM:5") {
      REQUIRE(character.attribute_cost(CharacterAttributeType::ST) == 20.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::IQ) == -20.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::DX) == 60.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::HT) == -20.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::HP) == 2.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::WILL) == -5.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::PER) == 10.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::FP) == 9.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::BS) == 10.0);
      REQUIRE(character.attribute_cost(CharacterAttributeType::BM) == 5.0);
    }
  }
}
