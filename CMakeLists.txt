cmake_minimum_required(VERSION 3.30)
project(Proiect)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(Proiect
    inc/User.hpp
        inc/Movie.hpp
    inc/Watchlist.hpp
    inc/Category.hpp
    inc/Actor.hpp
        main.cpp
        inc/Content.hpp
        inc/Episode.hpp
        src/User.cpp
        src/Movie.cpp
        inc/Menu.hpp
        src/Menu.cpp
        src/TVShow.cpp
        src/Content.cpp
        src/Episode.cpp
        src/Actor.cpp)
