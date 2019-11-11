add_library(bchestcore SHARED
  Character.cpp
  CharacterAttribute.cpp
  PrimaryAttribute.cpp
  SecondaryAttribute.cpp
)

set_target_properties(bchestcore
  PROPERTIES VERSION 0.1.0
)

target_include_directories(bchestcore
  PUBLIC include
  PRIVATE .
)

add_subdirectory(test)
