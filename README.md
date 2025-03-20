This project is a simple C program I made in 2023 that solves Sudoku puzzles. It uses a grid of squares and groups them into 3×3 boxes.

The main data structures are the Square, Box, and Sudoku types. Each Square holds a number and an array of possible candidates. Boxes group nine squares, and the Sudoku structure holds the entire puzzle.

The project is divided into several files. The header file defines the data structures and function prototypes. Other files, like those for puzzles, rows, boxes, and individual squares, handle specific parts of the solving process.

The solver uses constraint propagation. When a square is solved, the program updates the possibilities in its row, column, and box. It looks for cases where a candidate appears only once in a row or a box to set the number.

The main function runs a loop that applies these strategies until the puzzle is solved or no further progress is possible. The puzzle is printed both before and after solving.
