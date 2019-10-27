add_library(bchestcore SHARED
  BaseAttribute.cpp
  BasicAttribute.cpp
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
