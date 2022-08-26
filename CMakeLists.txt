# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.24.1)

# Name the project
project(app)

set(wxWidgets_DIR "wxWidget/wx_install/lib/cmake/wxWidgets")
# Request the required wxWidgets libs
find_package(wxWidgets 3.2 COMPONENTS core base REQUIRED CONFIG)

# Include the wxWidgets use file to initialize various settings
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

# Define a variable containing a list of source files for the project
set(SRC_FILES
    app.cpp
)

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
