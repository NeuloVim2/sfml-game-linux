add_executable(vector_test vector_test.cpp)

target_link_libraries(vector_test gtest gtest_main gmock)

message("Project source dir value: ${PROJECT_SOURCE_DIR}")

include(GoogleTest)
gtest_discover_tests(vector_test 
         # set a working directory so your project root so that you can find test data via paths relative to the project root
         WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
         PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)