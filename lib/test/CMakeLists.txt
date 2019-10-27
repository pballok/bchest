add_executable(test_bchestcore
  test_main.cpp
  test_character.cpp
)

target_link_libraries(test_bchestcore
  bchestcore
)

add_dependencies(test_bchestcore
  catch2
)

target_include_directories(test_bchestcore
  PRIVATE .
  PRIVATE ..
  PRIVATE ${CATCH2_INCLUDE_DIR}
)

add_test(
  NAME    TestBchestCore
  COMMAND test_bchestcore
)
