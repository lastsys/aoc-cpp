add_library(util SHARED split.cc)

add_executable(util_test test.cc)
target_link_libraries(util_test util)
add_test(NAME util_test COMMAND util_test)
