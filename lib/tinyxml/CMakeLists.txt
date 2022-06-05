cmake_minimum_required(VERSION 2.8)
project(tinyxml)

# Application source
set(APPLICATION_SOURCE
    tinyxml.cpp
    tinystr.cpp
    tinyxmlerror.cpp
    tinyxmlparser.cpp
)

# Install settings
set(CMAKE_INSTALL_PREFIX "${TINYXML_SOURCE_DIR}")