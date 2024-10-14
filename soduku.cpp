#include <iostream>
#define N 9 // Size of the grid (9x9)

using namespace std;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number at the given position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is not in the current row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if 'num' is not in the current column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not in the current 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int grid[N][N], int row, int col) {
    // If we have reached the last row and last column, we're done
    if (row == N - 1 && col == N) {
        return true;
    }

    // Move to the next row if we reach the end of a column
    if (col == N) {
        row++;
        col = 0;
    }

    // If the cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try placing numbers 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Place the number and move to the next cell
            grid[row][col] = num;

            // Recursively solve the rest of the board
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }

            // If placing the number didn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // If no number can be placed, return false (triggering backtracking)
    return false;
}

int main() {
    // Sample Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Solve the Sudoku puzzle
    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid); // Print the solved puzzle
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
