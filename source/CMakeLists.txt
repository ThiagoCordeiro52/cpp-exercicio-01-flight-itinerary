cmake_minimum_required(VERSION 3.15)
project ( FlightItinerary VERSION 1.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 11)

#=== Lib target ===
set( LIB_NAME "route" )
add_library( ${LIB_NAME} src/route.cpp)
set_target_properties( ${LIB_NAME} PROPERTIES CXX_STANDARD 11 )

# #=== Test target ===
set ( TEST_NAME "all_tests")
add_subdirectory(tests)

add_custom_target(
    run_tests
    COMMAND ${TEST_NAME} 2> /dev/null 
    DEPENDS ${LIB_NAME}
)
