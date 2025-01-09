message(STATUS "Fetching Google Test...")

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)