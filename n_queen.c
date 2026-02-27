
/*

*** une case = (col, row)
*** reine déjà placée → (previous_col, queen[previous_col])
*** reine testée → (column_to_place, row_to_test)

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SAFE 1
#define NOT_SAFE 0

static int is_safe(int *queen, int col_to_place, int row_to_test)
{
	int previous_col = 0;
	while (previous_col < col_to_place)
	{
		if (queen[previous_col] == row_to_test) // Si une reine est déjà sur la même ligne, pas bon
			return (NOT_SAFE);
		if (queen[previous_col] - previous_col == row_to_test - col_to_place) // diagonale descendente
									 // si les deux cases sont sur 
									 // la même diagonale principale
			return (NOT_SAFE);
		if (queen[previous_col] + previous_col == row_to_test + col_to_place) // diagonale montante
			return (NOT_SAFE);
		previous_col++;
	}
	return (SAFE);
}

void	print_board(int *queen, int size)
{
	int col = 0;
	while (col < size)
	{
		if (col > 0)
			printf(" ");
		printf("%d", queen[col]);
		col++;
	}
	printf("\n");
}

void	solve(int *queen, int size, int col_to_fill)
{
	int row_to_test = 0;
	if (col_to_fill == size)
	{
		print_board(queen, size);
		return ;
	}
	while (row_to_test < size)
	{
		if (is_safe(queen, col_to_fill, row_to_test) == SAFE)
		{
			queen[col_to_fill] = row_to_test;
			solve(queen, size, col_to_fill + 1);
		}
		row_to_test++;
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
