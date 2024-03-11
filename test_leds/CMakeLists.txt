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

file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../modules/generated)

# generate the header file into the source tree as it is included in the RP2040 datasheet
pico_generate_pio_header(main ${CMAKE_CURRENT_LIST_DIR}/../modules/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/../modules/generated)

target_include_directories(main PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(main
    pico_stdlib
    hardware_pio
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)

example_auto_set_url(main)

# Additionally generate python and hex pioasm outputs for inclusion in the RP2040 datasheet
add_custom_target(datasheet DEPENDS ${CMAKE_CURRENT_LIST_DIR}/../modules/generated/ws2812.py)
add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/../modules/generated/ws2812.py
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/../modules/ws2812.pio
        COMMAND Pioasm -o python ${CMAKE_CURRENT_LIST_DIR}/../modules/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/../modules/generated/ws2812.py
        VERBATIM)
add_dependencies(main datasheet)