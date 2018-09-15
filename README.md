# Data Structures

This project is a low-level implementation of Data Structures that I learned about
in a standard Data Structures course at NC State. We were taught in Java, but to
increase efficiency and develop structures for later projects, this project provides
lower-level implementations.

## Installation

The project is developed in CLion and uses CMake to build the source. The 
`CMakeLists.txt` file can be used with CMake to build the project.

## Organization

The project has two targets. The first target builds all the data structures along
with `main.c`, which is currently an empty entry point into the program.

The second target builds all the data structures along with a unit test framework
I wrote for the project. The entry point for this target is `test/test.c`. Unit 
tests are located in `test/`. 

## Running the Project

To run the tests, build and execute the `DataStructuresTest` target in CMake. The 
data structures are documented at the source level, but usage is demonstrated in
the unit tests.

## License

The project is licensed under GNU v3. Feel free to use/adapt the code!