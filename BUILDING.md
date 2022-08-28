# Building Quadratic Equation

## Prerequisites

- **g++** >= 9.3
- **GNU Make** >= 4.2
- **CMake** >= 3.16

## Installation process on Linux

1. Clone Quadratic Equation from GitHub project.
    ```
    $ git clone https://github.com/MeerkatBoss/quadratic-equation.git
    ```
2. Configure Quadratic Equation using CMake
    ```
    $ mkdir build && cd build
    $ cmake -DCMAKE_BUILD_TYPE=Release ..
    ```
3. Build Quadratic Equation
    ```
    $ make
    ```
4. Test the build
    ```
    $ cd ..
    $ build/tests/tests
    ```
5. Install Quadratic Equation
    ```
    $ cd build
    $ make install
    ```
6. You can now run Quadratic Equation from command-line
    ```
    $ quad
    ```