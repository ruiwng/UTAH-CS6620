cmake_minimum_required(VERSION 2.8)
project(raytracer)

 # Clang configuration
 if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

 set(CLANG_CXX_FLAGS "-std=c++11 -m64")

 if(BUILD_DEBUG)
   set(CMAKE_BUILD_TYPE Debug)
   set(CLANG_CXX_FLAGS "${CLANG_CXX_FLAGS} -g")
 else(BUILD_DEBUG)
   set(CLANG_CXX_FLAGS "${CLANG_CXX_FLAGS} -O3")
   set(CLANG_CXX_FLAGS "${CLANG_CXX_FLAGS} -funroll-loops")
   set(CLANG_CXX_FLAGS "${CLANG_CXX_FLAGS} -Wno-narrowing")
   set(CLANG_CXX_FLAGS "${CLANG_CXX_FLAGS} -Wno-deprecated-register")
 endif(BUILD_DEBUG)

 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLANG_CXX_FLAGS}")

endif()

include_directories(lib/cyCodeBase)
include_directories(lib/lodepng)
include_directories(lib/tinyxml)
include_directories(/usr/local/include)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

set(APPLICATION_SOURCE
    raytracer.cpp
    viewport.cpp
    xmlload.cpp
    lib/lodepng/lodepng.cpp
    lib/tinyxml/tinyxml.cpp
    lib/tinyxml/tinystr.cpp
    lib/tinyxml/tinyxmlerror.cpp
    lib/tinyxml/tinyxmlparser.cpp
)

#-------------------------------------------------------------------------------
# Add executable
#-------------------------------------------------------------------------------
add_executable(raytracer ${APPLICATION_SOURCE})

target_link_libraries(raytracer
    ${GLUT_LIBRARIES}
    ${OPENGL_LIBRARIES}
)
