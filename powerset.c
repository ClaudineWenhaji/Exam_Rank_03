/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:01:41 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/03/02 15:17:59 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	find_solutions(int *set, int *subset, int target, int set_size, int pos, int subset_size, int subset_sum)
{
	int i = 0;
	if (pos == set_size)
	{
		if (subset_sum == target)
		{
			while (i < subset_size)
			{
				if (i > 0)
					printf(" ");
				printf("%d", subset[i]);
				i++;
			}
			printf("\n");
		}
		return ;
	}
	subset[subset_size] = set[pos];
	find_solutions(set, subset, target, set_size, pos + 1, subset_size + 1, subset_sum + set[pos]);
	find_solutions(set, subset, target, set_size, pos + 1, subset_size, subset_sum);
}

int	main(int ac, char **av)
{
	int *set;
	int *subset;
	int size;
	int target;

	target = atoi(av[1]);
	size = ac - 2;
	if (size == 2)
	{
		printf("\n");
		return (0);
	}
	set = malloc(sizeof(int) * size);
	if (!set)
		return (1);
	subset = malloc(sizeof(int) * size);
	if (!subset)
		return (1);
	int i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
	find_solutions(set, subset, target, size, 0, 0, 0);
	free(set);
	free(subset);
	return (0);
}
