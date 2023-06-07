cmake_minimum_required(VERSION 3.14)
project(SFMLGame)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

set(CMAKE_PREFIX_PATH C:/)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

set(SOURCE_FILES
        src/main.cpp src/Game.cpp src/Game.h
        src/tmxsrc/FreeFuncs.cpp
        src/tmxsrc/ImageLayer.cpp
        src/tmxsrc/LayerGroup.cpp
        src/tmxsrc/Map.cpp
        src/tmxsrc/meson.build
        src/tmxsrc/miniz.c
        src/tmxsrc/miniz.h
        src/tmxsrc/Object.cpp
        src/tmxsrc/ObjectGroup.cpp
        src/tmxsrc/ObjectTypes.cpp
        src/tmxsrc/Property.cpp
        src/tmxsrc/TileLayer.cpp
        src/tmxsrc/Tileset.cpp
        src/tmxsrc/Tiles.cpp
        src/tmxsrc/Tiles.h
        src/tmxsrc/detail/pugixml.cpp
        src/tmxsrc/detail/pugixml.cpp
        src/Menus/MainMenu.cpp
        src/Menus/MainMenu.h
        src/GameObjects/player.cpp
        src/GameObjects/player.h
        src/Tilemap/Room1.cpp
        src/Tilemap/Room1.h
        src/Menus/MainMenu.cpp
        src/Menus/MainMenu.h
        src/GameObjects/playerMovement.cpp
        src/GameObjects/playerMovement.h
        src/GameObjects/GameObject.cpp
        src/GameObjects/GameObject.h
        src/GameObjects/player.cpp
        src/GameObjects/player.h
        src/GameObjects/Vector2.cpp
        src/GameObjects/Vector2.h
        src/GameObjects/BoundingBox.cpp
        src/GameObjects/BoundingBox.h
        src/Menus/MenuSwitcher.cpp
        src/Menus/MenuSwitcher.h
        src/Menus/GameOver.cpp
        src/Menus/GameOver.h
        src/Tilemap/Room2.cpp
        src/Tilemap/Room2.h
        src/GameObjects/Box.cpp
        src/GameObjects/Box.h
        src/GameObjects/PressurePlate.cpp
        src/GameObjects/PressurePlate.h
        src/Tilemap/Room3.cpp
        src/Tilemap/Room3.h
        src/GameObjects/Key.cpp
        src/GameObjects/Key.h
        src/GameObjects/UIElement.cpp
        src/GameObjects/UIElement.h src/Tilemap/Room4.cpp src/Tilemap/Room4.h src/GameObjects/Achievements.cpp src/GameObjects/Achievements.h)


add_executable(SFMLGame ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries (SFMLGame sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)
