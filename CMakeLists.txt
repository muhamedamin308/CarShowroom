cmake_minimum_required(VERSION 3.22)
project(final_showroom_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(final_showroom_project)

add_executable(final_showroom_project
        final_showroom_project/admin.cpp
        final_showroom_project/admin.h
        final_showroom_project/buy_rent.cpp
        final_showroom_project/buy_rent.h
        final_showroom_project/car.cpp
        final_showroom_project/car.h
        final_showroom_project/cars.cpp
        final_showroom_project/cars.h
        final_showroom_project/final_showroom_project.cpp
        final_showroom_project/garage.cpp
        final_showroom_project/garage.h
        final_showroom_project/Register.cpp
        final_showroom_project/Register.h
        final_showroom_project/service.cpp
        final_showroom_project/service.h
        final_showroom_project/service_process.cpp
        final_showroom_project/service_process.h
        final_showroom_project/showrooms.cpp
        final_showroom_project/showrooms.h
        final_showroom_project/user.cpp
        final_showroom_project/user.h)
