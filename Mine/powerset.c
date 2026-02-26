/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:14:03 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/26 12:35:27 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	find_solutions(int *set, int *subset, int target, int set_size, int pos, int subset_size, int subset_sum)
{
	int	i = 0;

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
	int	*set;
	int	*subset;
	int	target;
	int	set_size;
	int	i;

	if (ac < 2)
		return (1);

	target = atoi(av[1]);
	set_size = ac - 2;
	
	if (set_size == 0)
	{
		printf("\n");
		return (0);
	}
	
	set = malloc(sizeof(int) * set_size);
	if (!set)
		return (1);
	subset = malloc(sizeof(int) * set_size);
	if (!subset)
		return (1);
	i = 0;
	while (i < set_size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}

	find_solutions(set, subset, target, set_size, 0, 0, 0);

	free(set);
	free(subset);
	return (0);
}
