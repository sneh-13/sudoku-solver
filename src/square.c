#include "sudoku.h"

int solveSquare(Square * square)
{
    int x;

    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (square->possible[x] == 0)
        {
            square->number = x + 1;
            square->solvable = 0;
            UNSOLVED--;
            break;  // Exit after setting the number
        }
    }
    return square->number;  // Return the solved number (or you can simply return 1)
}
