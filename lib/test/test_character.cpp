#include "Character.h"

#include "Character.h"

#include <catch2/catch.hpp>

SCENARIO("Default Attribute values", "[Attributes]")
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
  }
}

SCENARIO("Default Attribute costs", "[Attributes]")
{
  GIVEN("a default-constructed Character") {
    Character character("Player");

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
