cmake_minimum_required(VERSION 3.26)
project(term_paper)

set(CMAKE_CXX_STANDARD 17)

add_executable(term_paper main.cpp
        employee.cpp
        employee.h
        project.cpp
        project.h
        department.cpp
        department.h
        company.cpp
        company.h
)
