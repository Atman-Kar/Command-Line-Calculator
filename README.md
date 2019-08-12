# Command Line Calculator

This program solves a mathematical expression (only with +,-,/,x) using BODMAS rule. The program makes use of the Shunting-Yard Algorithm.

To run the program, go to your terminal and type in:

```
$ gcc calc.c main.c sy.c polish_calc.c -o calc

``` 

And then,

```
$ ./calc
```

If you want to pass in a file, with lines of expressions

```
$ ./calc filename.txt
```