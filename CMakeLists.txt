cmake_minimum_required(VERSION 3.11)

# Project name
project(Num_Conv_Cpp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt5 packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Enable AUTOMOC to handle Q_OBJECT macro
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add the sources
set(SOURCES
    main.cpp
    converter.cpp
)

# Add the header files
set(HEADERS
    converter.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link the Qt5 libraries
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)

# Use the UI files (optional, if you use .ui for designing the interface)
#set(UI_FILES
#    mainwindow.ui
#)

# Run the uic for the UI files
#qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Add the generated UI headers to the target
#target_sources(${PROJECT_NAME} PRIVATE ${UI_HEADERS})
