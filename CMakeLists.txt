cmake_minimum_required(VERSION 3.28)
project(LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    # Define the path to the OpenAL DLL based on architecture
    set(OPENAL_DLL_PATH "${CMAKE_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll")

    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${OPENAL_DLL_PATH} $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
