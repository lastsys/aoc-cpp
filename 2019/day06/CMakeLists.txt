set(TASK_NAME 2019_day06)

add_library(${TASK_NAME}_lib SHARED day06.cc)

add_executable(${TASK_NAME} main.cc)
target_link_libraries(${TASK_NAME} ${TASK_NAME}_lib util)

add_executable(${TASK_NAME}_test test.cc)
target_link_libraries(${TASK_NAME}_test ${TASK_NAME}_lib util)
add_test(NAME ${TASK_NAME}_test COMMAND ${TASK_NAME}_test)
