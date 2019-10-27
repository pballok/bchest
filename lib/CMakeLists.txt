add_library(bchestcore SHARED
  BaseAttribute.cpp
  FixedAttribute.cpp
)

set_target_properties(bchestcore
  PROPERTIES VERSION 0.1.0
)

target_include_directories(bchestcore
  PUBLIC include
  PRIVATE .
)
