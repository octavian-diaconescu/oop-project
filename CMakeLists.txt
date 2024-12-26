# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(Proiect)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# You aren't supposed to be using this, but convenience...
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "inc/*")
file(GLOB_RECURSE TESTS RELATIVE ${CMAKE_SOURCE_DIR} "test/*.cpp")
include_directories(inc)
include_directories(include)
include_directories(src)

option(WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(USE_ASAN "Use Address Sanitizer" OFF)
option(USE_MSAN "Use Memory Sanitizer" OFF)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "install_dir" CACHE PATH "..." FORCE)
endif ()

# Suppression file for MSAN
set(MSAN_SUPPRESSION_FILE "${CMAKE_SOURCE_DIR}/msan_suppressions.txt")
file(WRITE ${MSAN_SUPPRESSION_FILE}
        "# Suppress uninitialized memory in standard streams\n
race:std::istream\n
race:std::ifstream\n
race:std::ofstream\n")

# Pass the suppression file to MSAN via the MSAN_OPTIONS environment variable
if (USE_MSAN)
    set(MSAN_OPTIONS "suppressions=${MSAN_SUPPRESSION_FILE}")
    message("MSAN_OPTIONS=${MSAN_OPTIONS}")
endif ()

# Custom function for sanitizers
function(set_custom_stdlib_and_sanitizers target add_apple_asan)
    if (MSVC)
        # see https://gitlab.kitware.com/cmake/cmake/-/issues/24922
        set_target_properties(${target} PROPERTIES VS_USER_PROPS "${CMAKE_SOURCE_DIR}/disable_modules.props")
        target_compile_options(${target} PRIVATE /experimental:module-)
        if (USE_ASAN)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:/fsanitize=address>")
        endif ()
        return()
    endif ()

    if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND NOT WIN32)
        detect_libcpp()
        if (HAS_LIBCPP)
            target_compile_options(${target} PRIVATE -stdlib=libc++)
            target_link_options(${target} PRIVATE -stdlib=libc++)
        else ()
            target_compile_options(${target} PRIVATE -stdlib=libstdc++)
            target_link_options(${target} PRIVATE -stdlib=libstdc++)
        endif ()
    endif ()

    if (APPLE)
        if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" AND add_apple_asan MATCHES true)
            if (USE_ASAN)
                target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
                target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
            endif ()
        endif ()
    elseif (UNIX)
        if (USE_ASAN)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
            target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=address,undefined>")
        elseif (USE_MSAN)
            target_compile_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=memory,undefined;-fsanitize-recover=memory,undefined;-fsanitize-memory-track-origins>")
            target_link_options(${target} PRIVATE "$<${debug_mode}:-fsanitize=memory,undefined;-fsanitize-recover=memory,undefined;-fsanitize-memory-track-origins;-Wl,-rpath,tools/llvm-project/build/lib>")
        endif ()
    endif ()
endfunction()

###############################################################################

# FetchContent for dependencies
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

###############################################################################

# Executable setup
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

if (USE_MSAN)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E env MSAN_OPTIONS=${MSAN_OPTIONS} $<TARGET_FILE:${PROJECT_NAME}>
            COMMENT "Setting MSAN_OPTIONS for ${PROJECT_NAME}")
endif ()

# Set sanitizers
set_custom_stdlib_and_sanitizers(${PROJECT_NAME} true)

###############################################################################

# Testing setup
enable_testing()
add_executable(project
        inc/Builder.hpp
        inc/Category.hpp
        inc/Content.hpp
        inc/Episode.hpp
        inc/Menu.hpp
        inc/Movie.hpp
        inc/Storage.hpp
        inc/TVShow.hpp
        inc/User.hpp
        inc/Watchlist.hpp
        main.cpp
        src/Builder.cpp
        src/Category.cpp
        src/Content.cpp
        src/Episode.cpp
        src/Menu.cpp
        src/Movie.cpp
        src/TVShow.cpp
        src/User.cpp
        src/Watchlist.cpp
)

target_link_libraries(
        Proiect
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Proiect)
