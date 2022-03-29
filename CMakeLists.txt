cmake_minimum_required(VERSION 3.17)
project(taxi)

set(CMAKE_CXX_STANDARD 17)

add_executable(taxi main.cpp Users.cpp Users.h Car.cpp Car.h CoordinateSystem.cpp CoordinateSystem.h CarTypes.h PassengerGateway.cpp PassengerGateway.h DriverGateway.cpp DriverGateway.h System.cpp System.h DataBase.cpp DataBase.h AdminGateway.cpp AdminGateway.h Devices.cpp Devices.h)