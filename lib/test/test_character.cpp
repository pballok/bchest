#include "Character.h"

#include <catch2/catch.hpp>

SCENARIO("Attribute Default values", "[CharacterAttribute]")
{
  GIVEN("A default Character") {
    Character player("Player");

    THEN("all attributes must have the default value") {
      REQUIRE(player.attribute_value(CharacterAttributeType::ST) == 10.0);
    }
  }
}