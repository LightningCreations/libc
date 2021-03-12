add_executable(hello hello.c)
set_target_properties(hello PROPERTIES LINK_FLAGS "-nostdlib")
target_link_libraries(hello c crt)

add_test(hello hello)
