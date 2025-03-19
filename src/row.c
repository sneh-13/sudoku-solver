#include "sudoku.h"

/*
 * int rowSingles(Square *** sudoku)
 *
 * Loop through each row to find a candidate number (1-9)
 * that is possible in exactly one unsolved square.
 * If found, the candidate number is assigned to that square,
 * the square is marked as solved, and updateSudoku is called.
 */
int rowSingles(Square *** sudoku) {
    int i, j, col;
    int count;
    int candidateCol;

    // Iterate over each row
    for (i = 0; i < SIZE_ROWS; i++) {
        // For each candidate number (represented as index 0 for 1, 1 for 2, etc.)
        for (j = 0; j < 9; j++) {
            count = 0;
            // Check each column in the current row
            for (col = 0; col < SIZE_COLUMNS; col++) {
                // Skip cells that are already solved
                if (sudoku[i][col]->number != 0)
                    continue;
                // If candidate (j+1) is still possible (possible[j] == 0 means not eliminated)
                if (sudoku[i][col]->possible[j] == 0) {
                    count++;
                    candidateCol = col;
                }
                // If more than one cell can have the candidate, exit the inner loop
                if (count > 1)
                    break;
            }
            // If the candidate appears exactly once in the row
            if (count == 1) {
                sudoku[i][candidateCol]->number = j + 1;
                sudoku[i][candidateCol]->solvable = 0;
                UNSOLVED--;
                updateSudoku(sudoku, i, candidateCol);
                return 1;  // Progress made
            }
        }
    }
    return 0;  // No progress found in any row
}
