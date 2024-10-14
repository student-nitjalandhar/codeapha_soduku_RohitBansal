# Sudoku Solver

## Introduction
This project implements a Sudoku solver using the Backtracking algorithm in C++. The solver is capable of solving Sudoku puzzles of varying difficulty levels. The program reads a 9x9 Sudoku grid, attempts to fill in the grid following the Sudoku rules, and prints the solution if one exists.

## Features
- Solves any 9x9 Sudoku puzzle.
- Uses Backtracking algorithm to efficiently solve puzzles.
- Outputs the solved Sudoku grid.
  
## Sudoku Rules
1. Each row must contain the numbers 1-9 without repetition.
2. Each column must contain the numbers 1-9 without repetition.
3. Each 3x3 subgrid must contain the numbers 1-9 without repetition.

## Code Explanation
- printGrid(): Prints the Sudoku grid in a readable format.
- isSafe(): Checks if placing a number in a particular cell is allowed based on Sudoku rules.
-solveSudoku(): Solves the puzzle using Backtracking. It recursively tries placing digits and backtracks if a solution isn't found.

## How to Run the Program

1. Install C++ Compiler:
   - Ensure that you have a C++ compiler (like GCC or Clang) installed on your system.

2. Compile the Program:
   - Open a terminal or command prompt.
   - Navigate to the directory where the `sudoku_solver.cpp` file is located.
   - Compile the program using the following command:

     ```bash
     g++ sudoku_solver.cpp -o sudoku_solver
     ```

3. Run the Program:
   - After compiling, run the executable with this command:

     ```bash
     ./sudoku_solver
     ```

4. Output:
   - The program will print the solved Sudoku grid if a solution exists. If not, it will print "No solution exists!"

## Example Input

The program comes with a pre-defined unsolved Sudoku puzzle in the `main()` function:

