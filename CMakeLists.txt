# Build documentation
option(BUILD_DOC "Build documentation" ON)

# Check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # Set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Progress output
    message("Doxygen build started.")

    # Generate docs
    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

endif()

# Set the CMake min. version required to configure the code
cmake_minimum_required(VERSION 3.10)
# Set the project name
project("rpg")

# Include all the files that follow the pattern
file(GLOB classes "include/*.h" "src/*.cpp")
# Create an executable with the specified name
# including the previously cteated set of files
add_executable(rpg main.cpp ${classes})

# Add include folder to handle header files
target_include_directories(rpg PRIVATE "include/")

# doxygen_add_docs("rpg.pdf" ALL)

# Make sure to use c++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)