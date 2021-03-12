add_executable(hello-write hello-write.c)
set_target_properties(hello-write PROPERTIES LINK_FLAGS "-nostdlib")
target_link_libraries(hello-write c crt)

add_test(hello-write hello-write)
