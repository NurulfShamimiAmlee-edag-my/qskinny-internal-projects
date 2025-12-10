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
# Explicitly tell CMake where to find QSkinny-ARM
set(QSkinny_DIR "/opt/qskinny-arm/lib/cmake/QSkinny" CACHE PATH "QSkinny CMake config" FORCE)

# Explicitly tell CMake where to find QSkinny-Host
# set(QSkinny_DIR "/opt/qskinny/lib/cmake/QSkinny" CACHE PATH "QSkinny CMake config" FORCE)
find_package(QSkinny REQUIRED)
 
# add_executable(smartoffice
#     src/main.cpp
#     src/TopBar.cpp
#     src/MainPage.cpp
#     src/SettingsPage.cpp
#     src/RoomPage.cpp
#     src/SummaryPage.cpp
#     src/PageViewer.cpp
#     src/NavigationBox.cpp
#     src/BottomSection.cpp
#     src/MySkinFactory.cpp
#     src/TopBarMenuButton.cpp
#     src/TopBarGraphicLabel.cpp
#     src/NavigationButton.cpp
#     src/MainPageTextLabel.cpp
#     src/MainPagePushButton.cpp
#     src/MainPageGraphicLabel.cpp
#     src/MainPageSwitchButton.cpp
#     src/DragGraphicLabel.cpp
#     src/DropBox.cpp
#     src/Sliders.cpp
#     src/SliderBox.cpp
#     src/TemperatureButton.cpp
#     src/RoomPageTab.cpp
#     src/RoomImageWithButtonsBox.cpp
#     src/SliderButtons.cpp
#     src/LightButton.cpp
#     src/BlindGraphicLabel.cpp
#     src/UsageBox.cpp
#     src/SingletonBannerDb.cpp
#     src/MasterSwitchButton.cpp
#     src/ImageButtons.cpp
#     src/Diagram.cpp
#     src/DiagramSkinlet.cpp
#     src/DiagramSegmentsNode.cpp
#     src/DiagramDataNode.cpp
#     src/UsageDiagram.cpp
#     resources.qrc)

 
# target_link_libraries(smartoffice PRIVATE
#     Qt6::Quick
#     Qsk::QSkinny)

# Point to the ARM-built QSkinny
set(QSkinny_ROOT "/opt/qskinny-arm")

# Add QSkinny-ARM include directories
include_directories(${QSkinny_ROOT}/include)

# Add QSkinny-ARM library directory
link_directories(${QSkinny_ROOT}/lib)

# Find Qt6 (if not already done)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick)

# Your executable
add_executable(smartoffice
    src/main.cpp
    src/TopBar.cpp
    src/MainPage.cpp
    src/SettingsPage.cpp
    src/RoomPage.cpp
    src/SummaryPage.cpp
    src/PageViewer.cpp
    src/NavigationBox.cpp
    src/BottomSection.cpp
    src/MySkinFactory.cpp
    src/TopBarMenuButton.cpp
    src/TopBarGraphicLabel.cpp
    src/NavigationButton.cpp
    src/MainPageTextLabel.cpp
    src/MainPagePushButton.cpp
    src/MainPageGraphicLabel.cpp
    src/MainPageSwitchButton.cpp
    src/DragGraphicLabel.cpp
    src/DropBox.cpp
    src/Sliders.cpp
    src/SliderBox.cpp
    src/TemperatureButton.cpp
    src/RoomPageTab.cpp
    src/RoomImageWithButtonsBox.cpp
    src/SliderButtons.cpp
    src/LightButton.cpp
    src/BlindGraphicLabel.cpp
    src/UsageBox.cpp
    src/SingletonBannerDb.cpp
    src/MasterSwitchButton.cpp
    src/ImageButtons.cpp
    src/Diagram.cpp
    src/DiagramSkinlet.cpp
    src/DiagramSegmentsNode.cpp
    src/DiagramDataNode.cpp
    src/UsageDiagram.cpp
    resources.qrc)

# Link against QSkinny-ARM and Qt
target_link_libraries(smartoffice
    PRIVATE
        Qsk::QSkinny
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
)   
