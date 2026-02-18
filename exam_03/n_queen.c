
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SAFE 1
#define NOT_SAFE 0

static int is_safe(int *queens, int simdi_col, int test_row)
{
	int once_col = 0;
	while (once_col < simdi_col)
	{
		if (queens[once_col] == test_row)
			return (NOT_SAFE);
		if (queens[once_col] - once_col == test_row - simdi_col)
			return (NOT_SAFE);
		if (queens[once_col] + once_col == test_row + simdi_col)
			return (NOT_SAFE);
		once_col++;
	}
	return (SAFE);
}

void	print_board(int *queens, int size)
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

void	solve(int *queens, int size, int simdi_col)
{
	int test_row = 0;
	if (simdi_col == size)
	{
		print_board(queens, size);
		return ;
	}
	while (test_row < size)
	{
		if (is_safe(queens, simdi_col, test_row) == SAFE)
		{
			queens[simdi_col] = test_row;
			solve(queens, size, simdi_col + 1);
		}
		test_row++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int size = atoi(argv[1]);
	if (size < 1)
		return (0);
	int *queens = malloc(sizeof(int) * size);
	if (!queens)
		return (0);
	if (size != 2 && size != 3)
		solve(queens, size, 0);
	free(queens);
	return (0);
}