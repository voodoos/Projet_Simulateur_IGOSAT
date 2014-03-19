# Version CMake
cmake_minimum_required (VERSION 2.8)

# Nom du projet
project (igosim)

# C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -std=c++11")

# Ajout des répértoires Core et BatteryModule au chemin de recherche
include_directories ("${PROJECT_SOURCE_DIR}/Core")
include_directories ("${PROJECT_SOURCE_DIR}/BatteryModule")
add_subdirectory (Core)
add_subdirectory (BatteryModule)
set (EXTRA_LIBS ${EXTRA_LIBS} Core)
set (EXTRA_LIBS ${EXTRA_LIBS} BatteryModule)


#ajout de l'executable
add_executable (igosim IGOsim.cpp)
target_link_libraries (igosim  ${EXTRA_LIBS})
