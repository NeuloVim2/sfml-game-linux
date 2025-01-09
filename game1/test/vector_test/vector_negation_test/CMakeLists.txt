add_executable(vector_negation_test vector_negation_test.cpp)

target_link_libraries(vector_negation_test gtest gtest_main gmock vector)

message("Building vector_comparement_test....")
gtest_discover_tests(vector_negation_test 
                     # set a working directory so your project root so that you can find test data via paths relative to the project root
                     WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test/vector_test/vector_negation_test"
                     PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test/vector_test/vector_negation_test"
                    #  PROPERTIES LABELS "Substraction"
                    #  PROPERTIES LABELS "All"
)