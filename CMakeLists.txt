cmake_minimum_required (VERSION 3.10)

project ("progtech-lab8")

add_executable (main "src/main.cpp" "include/main.h")
include_directories("include")


set(SFML_DIR "external/SFML/lib/cmake/SFML/")
find_package(SFML 3 REQUIRED COMPONENTS
	Graphics
	Window
	System
)


target_link_libraries(main PRIVATE SFML::Graphics SFML::Window SFML::System)

add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/external/SFML/bin"
        "$<TARGET_FILE_DIR:main>"
)