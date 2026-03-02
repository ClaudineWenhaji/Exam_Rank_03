/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:14:17 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/03/02 14:59:54 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_safe(int *queen, int row, int col)
{
	int i = 0;
	int abs;
	while (i < row)
	{
		abs = queen[i] - col;
		if (abs < 0)
			abs = -abs;
		if (queen[i] == col || abs == row - i)
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int *queen, int size)
{
	int i = 0;
	while (i < size)
	{
		if (i > 0)
			printf(" ");
		printf("%d", queen[i]);
		i++;
	}
	printf("\n");
}

void	solve(int *queen, int row, int size)
{
	if (row == size)
	{
		print_board(queen, size);
		return ;
	}
	int col = 0;
	while (col < size)
	{
		if (is_safe(queen, row, col))
		{
			queen[row] = col;
			solve(queen, row + 1, size);
		}
		col++;
	}	
}

int	main(int ac, char **av)
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
