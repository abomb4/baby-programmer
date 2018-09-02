cmake_minimum_required (VERSION 3.0)

# C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#find_package (Threads)

# include list
#include_directories(./include)
#add_library(spdlog INTERFACE)
#target_include_directories(
#    spdlog
#    INTERFACE
#    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
#    "$<INSTALL_INTERFACE:include>"
#)

# Source list
add_library(sorting
    sorting/sort.h
    sorting/sorting.h
    sorting/sorting.cpp
    sorting/select.cpp
    sorting/select.h
)

add_executable(baby main.cpp)

#target_link_libraries (fxserver ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries (fxserver ${MYSQL_LIBRARIES})
#target_link_libraries (fxserver ${MYSQLPP_LIBRARIES})

target_link_libraries (baby sorting)

# utils
#add_subdirectory(fxutils)
# target_link_libraries(fxserver fxutils)

# install
#install(TARGETS fxserver DESTINATION /usr/local/bin)
#install(FILES default.cfg RENAME fxserver.cfg DESTINATION /etc)

