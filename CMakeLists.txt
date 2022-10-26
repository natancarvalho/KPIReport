cmake_minimum_required(VERSION 3.22)
project(KPIReport)

set(CMAKE_CXX_STANDARD 14)

add_executable(KPIReport main.cpp include/functions.h include/functions.cpp include/queries.h include/events.h lib/events.cpp include/cars.h include/constants.h)
set(CMAKE_EXECUTABLE_SUFFIX .cgi)

install(TARGETS KPIReport
        DESTINATION /usr/lib/cgi-bin)

set(/usr/include/mysql-cppconn-8)
include_directories(/usr/include/mysql-cppconn-8/jdbc)
link_directories(/usr/include/mysql-cppconn-8/jdbc)
set(/usr/include/python3.10)
include_directories(/usr/include/python3.10)
link_directories(/usr/include/python3.10)
target_link_libraries(KPIReport mysqlcppconn python3.10)