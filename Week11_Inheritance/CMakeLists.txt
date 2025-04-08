cmake_minimum_required(VERSION 3.30)
project(Week11_Inheritance)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CIL constructor_initializer.cpp)
add_executable(ABC abstract_base_class.cpp)
add_executable(Virtual_Override virtual_override.cpp)
add_executable(Diamond_Problem diamond_problem.cpp)
