#include <stdlib.h>
#include <stdio.h>

#define SAFE 1
#define NOT_SAFE 0

static int is_safe(int *queens, int current_col, int test_row)
{
    int prev_col;

    prev_col = 0;
    while (prev_col < current_col)
    {
        if (queens[prev_col] == test_row)
            return NOT_SAFE;
        if (queens[prev_col] - prev_col == test_row - current_col)
            return NOT_SAFE;
        if (queens[prev_col] + prev_col == test_row + current_col)
            return NOT_SAFE;
        prev_col++;
    }
    return SAFE;
}

static void print_board(int *queens, int size)
{
    int col = 0;

    while (col < size)
    {
        if (col > 0)
            printf(" ");
        printf("%d", queens[col]);
        col++;
    }
    printf("\n");
}

static void solve(int *queens, int size, int current_col)
{
    int test_row = 0;

    if (current_col == size)
    {
        print_board(queens, size);
        return;
    }
    while (test_row < size)
    {
        if (is_safe(queens, current_col, test_row) == SAFE)
        {
            queens[current_col] = test_row;
            solve(queens, size, current_col + 1);
        }
        test_row++;
    }
}

int main(int argc, char **argv)
{
    int size;
    int *queens;

    if (argc != 2)
        return (0);
    size = atoi(argv[1]);
    if (size < 1)
        return (0);
    queens = malloc(sizeof(int) * size);
    if (!queens)
        return (0);
    solve(queens, size, 0);
    return (0);
}
