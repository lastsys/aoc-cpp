set(TASK_NAME 2019_day03)

add_library(${TASK_NAME}_lib SHARED day03.cc)

add_executable(${TASK_NAME} main.cc)
target_link_libraries(${TASK_NAME} ${TASK_NAME}_lib)

add_executable(${TASK_NAME}_test test.cc)
target_link_libraries(${TASK_NAME}_test ${TASK_NAME}_lib)
add_test(NAME ${TASK_NAME}_test COMMAND ${TASK_NAME}_test)
