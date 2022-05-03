cmake_minimum_required(VERSION 3.20)
project(ferma)

set(CMAKE_CXX_STANDARD 17)

add_executable(ferma main.cpp Player.cpp Menu.cpp Map.cpp Shop.cpp Chat.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML 2.5 COMPONENTS graphics network window audio system REQUIRED)

target_link_libraries(ferma sfml-system sfml-window sfml-graphics sfml-audio)
