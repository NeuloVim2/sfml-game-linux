add_executable(vector_addition_test vector_addition_test.cpp)

target_link_libraries(vector_addition_test gtest gtest_main gmock vector)

gtest_discover_tests(vector_addition_test 
                     # set a working directory so your project root so that you can find test data via paths relative to the project root
                     WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test/vector_test/vector_substraction_test"
                     PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test/vector_test/vector_addition_test" 
                    #  PROPERTIES LABELS "Addition"
                    #  PROPERTIES LABELS "All"
)
