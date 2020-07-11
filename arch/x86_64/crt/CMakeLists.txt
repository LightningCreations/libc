


add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/crt1.o
        COMMAND ${CMAKE_C_COMPILER} -ffreestanding -c ${CMAKE_CURRENT_SOURCE_DIR}/crt1.S
         -o ${CMAKE_CURRENT_BINARY_DIR}/crt1.o
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/crt1.S)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/crti.o
        COMMAND ${CMAKE_C_COMPILER} -ffreestanding -c ${CMAKE_CURRENT_SOURCE_DIR}/crti.S
        -o ${CMAKE_CURRENT_BINARY_DIR}/crti.o
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/crti.S)

add_custom_target(crt_build
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/crt1.o
        ${CMAKE_CURRENT_BINARY_DIR}/crti.o)

add_library(crt OBJECT IMPORTED GLOBAL)
set_property(TARGET crt PROPERTY IMPORTED_OBJECTS
        ${CMAKE_CURRENT_BINARY_DIR}/crt1.o
        ${CMAKE_CURRENT_BINARY_DIR}/crti.o)
add_dependencies(crt crt_build)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/crt1.o
        ${CMAKE_CURRENT_BINARY_DIR}/crti.o TYPE LIB)
