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
    $ make check
    ```
5. Install Quadratic Equation
    ```
    $ cd build
    $ sudo make install
    ```
6. You can now run Quadratic Equation from command-line
    ```
    $ quad
    ```

## Uninstalling
To uninstall Quadratic Equation run the following command from `build` directory:
```
$ sudo make uninstall
```