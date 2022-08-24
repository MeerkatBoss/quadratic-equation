# Quadratic equation solver

This program finds real roots of a given second-degree polynomial, solving
equations $ax^2 + bx + c = 0$ given the coefficients $a$, $b$ and $c$.

## Non-interactive mode
Coefficients can be provided via command-line arguments:

```
quad <a> <b> <c>
```

Upon receiving invalid values (letters, Inf, -Inf, NaN) or incorrect number
of values the program will terminate with exit code 1.

## Interactive mode
If no command-line arguments are provided, the program will launch in
interactive mode:
```
quad
This program solves equations ax^2 + bx + c = 0
Please, enter coefficients a, b and c
```
Program will prompt the user to enter three floating-point numbers. As long as
invalid values are provided, the program will repeatedly ask user for valid
input. Upon receiving end-of-file signal, the program will terminate with exit
code 0.

## Getting help
Help message is provided whenever program terminates abnormally due to invalid
input. User can manually get help message, using `-h` flag
```
quad -h
Usage:
    quad - to launch program in interactive mode
    quad <a> <b> <c> - to get roots of an equation ax^2 + bx + c = 0
    quad -h - to get this message
```

## Runtime errors
Upon encountering unexpected error during execution, program will print string
representation of encountered error and terminate with exit code 2. If you
encounter such error, please report it as an issue on GitHub and provide exact
steps to reproduce it.