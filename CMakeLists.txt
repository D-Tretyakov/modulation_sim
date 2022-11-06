# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.24.1)

# Name the project
project(DrawFunctions)

set(wxWidgets_DIR "wxWidget/wx_install/lib/cmake/wxWidgets")
# Request the required wxWidgets libs
find_package(wxWidgets 3.2 COMPONENTS core base REQUIRED CONFIG)

# Load eigen library
# eigen is in C:/Program Files (x86)/Eigen3
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

# Include the wxWidgets use file to initialize various settings
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

# Define a variable containing a list of source files for the project
set(SRC_FILES
    GUI/PlotGrid/PlotGrid.cpp
    GUI/GUI.cpp
    main.cpp
)

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_link_libraries (${PROJECT_NAME} Eigen3::Eigen)
