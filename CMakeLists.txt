cmake_minimum_required(VERSION 3.15)
project(Polinoms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Polinoms 
			   main.cpp
			   Polynom.cpp
			   Polynom.h 
			   Field.cpp 
			   Field.h 
			   Ring.cpp 
			   Ring.h)