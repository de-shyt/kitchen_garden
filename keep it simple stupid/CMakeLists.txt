cmake_minimum_required(VERSION 3.20)
project(draft1)

set(CMAKE_CXX_STANDARD 17)

add_executable(draft1 main.cpp Player.cpp Menu.cpp Map.cpp Shop.cpp Chat.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Users/NB/CLionProjects/lib/SFML/MinGW-64/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics network window audio system REQUIRED)
#find_package(JPEG)
#find_package(Freetype)

target_link_libraries(draft1 sfml-graphics)
