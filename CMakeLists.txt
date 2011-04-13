cmake_minimum_required(VERSION 2.6)
project(FitGamePack)

if(WIN32)
    include_directories("include")
    link_directories("${CMAKE_CURRENT_SOURCE_DIR}/library")
    set(SDLTTF_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/library/SDL_ttf.lib")
    set(SDLMIXER_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/library/SDL_mixer.lib")
    set(SDLIMAGE_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/library/SDL_image.lib")
    set(FITGY_LIBRARIES Fitgy ${SDL_LIBRARY} ${SDLTTF_LIBRARY} ${SDLMIXER_LIBRARY} ${SDLIMAGE_LIBRARY})
else(WIN32)
    find_package(PkgConfig)
    pkg_check_modules(GTKMM gtkmm-2.4)
    set(FITGY_LIBRARIES Fitgy ${SDL_LIBRARY} ${SDLTTF_LIBRARY} ${SDLMIXER_LIBRARY} ${SDLIMAGE_LIBRARY} ${GTKMM_LIBRARIES})
    
    link_directories( ${GTKMM_LIBRARY_DIRS} )
    include_directories( ${GTKMM_INCLUDE_DIRS} )
endif(WIN32)

find_package(SDL)
find_package(SDL_ttf)
find_package(SDL_mixer)
find_package(SDL_image)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -Wextra -pedantic -Wno-write-strings -std=c++0x)
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Fitgy)
add_subdirectory(TicTacToe)
add_subdirectory(Typer)
add_subdirectory(PingPong)