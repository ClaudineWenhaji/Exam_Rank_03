
/*

*** une case = (col, row)
*** reine déjà placée → (previous_col, queen[previous_col])
*** reine testée → (column_to_place, row_to_test)

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int is_safe(int *board, int row, int col)
{
	int i = 0;
	int abs;

	while (i < row)
	{
		abs = board[i] - col;

		if (abs < 0)
			abs = -abs;
		if (board[i] == col || abs == row - i)
			return (0);
		i++;
	}
	return (1);
}


void	solve(int *queen, int row, int size)
{
	if (row == size)
	{
		int	i = 0;
		while (i < size)
		{
			if (i > 0)
				printf(" ");
			printf("%d", queen[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	int	col = 0;
	while (col <size)
	{
		if (is_safe(queen, row, col))
		{
			queen[row] = col;
			solve(queen, row + 1, size);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int size = atoi(av[1]);
		if (size == 0)
		{
			printf("\n");
			return (0);
		}
		int *queen = malloc(sizeof(int) * size);
		if (!queen)
			return (0);
		solve(queen, 0, size);
		free(queen);
	}
	return (0);
}
