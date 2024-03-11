cmake_minimum_required(VERSION 3.21)

set(CMAKE_INCLUDES_DIR "../cmake_utils")

include(${CMAKE_INCLUDES_DIR}/pico_sdk_import.cmake)
include(${CMAKE_INCLUDES_DIR}/pico_extras_import_optional.cmake)
include(${CMAKE_INCLUDES_DIR}/cmake_install.cmake)
include(${CMAKE_INCLUDES_DIR}/example_auto_set_url.cmake)

include_directories(../modules)

project(pico-projects)

pico_sdk_init()

add_executable(main
    main.c
)

target_include_directories(main PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(main
    pico_stdlib
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)