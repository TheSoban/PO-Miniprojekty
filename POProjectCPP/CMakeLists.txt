cmake_minimum_required(VERSION "3.19.3")

project("Snake")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SFML_DIR "./libs/SFML-2.5.1/lib/cmake/SFML")
set(SOURCES "main.cpp" "Draw.cpp" "Food.cpp" "Game.cpp" "Menu.cpp" "Snake.cpp" "Store.cpp" "StoreItem.cpp" "Theme.cpp" "Utils.cpp" "Vector.cpp")

find_package(SFML COMPONENTS system graphics audio network REQUIRED)
add_executable ("${PROJECT_NAME}" "${SOURCES}")
target_link_libraries("${PROJECT_NAME}" PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)