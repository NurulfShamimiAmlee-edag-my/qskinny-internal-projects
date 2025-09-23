cmake_minimum_required(VERSION 3.27)
 
project(smartoffice
    VERSION 1.0.0
    LANGUAGES CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
 
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(QSkinny REQUIRED)
 
add_executable(smartoffice
    src/main.cpp)
 
target_link_libraries(smartoffice PRIVATE
    Qt6::Quick
    Qsk::QSkinny)
