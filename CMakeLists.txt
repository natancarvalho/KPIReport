cmake_minimum_required(VERSION 3.22)
project(DBConnect)

set(CMAKE_CXX_STANDARD 14)

add_executable(DBConnect main.cpp include/functions.h include/functions.cpp include/queries.h)
set(CMAKE_EXECUTABLE_SUFFIX cgi)

set(/usr/include/mysql-cppconn-8)
include_directories(/usr/include/mysql-cppconn-8/jdbc)
link_directories(/usr/include/mysql-cppconn-8/jdbc)
set(/usr/include/python3.10)
include_directories(/usr/include/python3.10)
link_directories(/usr/include/python3.10)
target_link_libraries(DBConnect mysqlcppconn python3.10)