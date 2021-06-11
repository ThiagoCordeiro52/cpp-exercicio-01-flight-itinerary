[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=4873959&assignment_repo_type=AssignmentRepo)
# Problem: Flight Connection

## Topic
Unidimensional array

## Problem
Given an unordered list of **flights** taken by someone, each represented as `(origin, destination)` pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return `null`. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights `[('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL',
'YYZ'), ('HKO', 'ORD')]` and starting airport `'YUL'`, you should return the list `['YUL', 'YYZ', 'SFO', 'HKO', 'ORD']`.

Given the list of flights `[('SFO', 'COM'), ('COM', 'YYZ')]` and starting airport `'COM'`, you should return `null`.

Given the list of flights `[('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]` and starting airport `'A'`, you should return the list `['A', 'B', 'C', 'A', 'C']`  even though `['A', 'C', 'A', 'B', 'C']` is also a valid itinerary. However, the first one is lexicographically smaller.

## Your Task

In this assignment you should write a function that takes in a list of flights and returns a string representing the complete flight itinerary your function found, if one exists, or `"null"` if no such a route exists.

A flight leg is to be represent as the struct below:
```c++
/// Pair representing a flight leg.
struct Pair {
    std::string orig; //!< origin airport.
    std::string dest; //!< destination airport.
};
```

The function prototype is:
```c++
std::string find_route( const std::string & start , Pair segs[], size_t sz );
```

where `start` is the starting airport string representation, `segs` is a regular array of flight legs, and `sz` is the number of flight legs stored in `segs`.

Note that in this repo there already exists unit tests to check whether your function works properly.
All you have to do is to edit the `src/route.cpp` source file and include your answer (code).

## Compiling and running the project

The project folder is organized as follows:
```
+─flights                 ---> Main project folder
  ├─── CMakeLists.txt     ---> CMake script file.
  ├─── build              ---> Folder where the output of the compilation will be sent to. [this folder will be created]
  ├─── tests              ---> Folder with the unit tests.
  └─── src                ---> Folder with the file you need to edit and write your solution in.
       ├─── route.h       ---> Header file with the route function specification.
       └─── route.cpp     ---> Source file where the route function should be coded. [edit this file]
```

1. Edit the file `flights/src/route.cpp` and code your solution.
2. Enter the main project folder:
```
cd flights
```
3. Execute the `cmake` command to create the makefiles. This command should create the folder `build` and create all the _Makefile_ inside this folder.
```
cmake -S . -B build
```
4. Execute the `cmake` command to **compile** the project `flights` inside the `build` folder. This statement should create a static lib inside `build` with the route function, `libfunc.a`, and an executable file to run the unit tests `tests/all_tests`.
```
cmake --build build
```

5. In case of any compiling error, please fix the problem and go back to the previous step. In case of a successful compilation, run the command below to enter the folder  `build` and run the tests.
```
cd build
make run_tests
```

6. In case of any test failure, please fix the problem and compile the project again, as described in Step 4. However, if you already are inside  `build` and wishes to compile again, you may run the commands below, instead of returning to Step 4 (which should be run outside `build`).
```
make
make run_tests
```

# Turning in your work

You may turn in your assignment in one of these two ways:
1. Create a compressed file with your code and upload it via SIGAA, at the proper task submission entry.
2. Commit your solution to the GitHub Classroom.

--------
&copy; DIMAp/IRAN 2021.
