
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	find_solutions(int *set, int *cur_subset, int target, int size, int index, int cur_size, int cur_sum)
{
	if (index == size)
	{
		if (cur_sum == target) // si vrai, affiche la combinaison
		{
			for (int i = 0 ; i < cur_size ; i++)
			{
				if (i > 0)
					printf(" ");
				printf("%d", cur_subset[i]);
			}
			printf("\n");
		}
		return ;
	}

	cur[cur_size] = set[index];
	find_solutions(set, cur_subset, target, size, index + 1, cur_size + 1, cur_sum + set[index]);
	find_solutions(set, cur_subset, target, size, index + 1, cur_size, cur_sum);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	
	int target = atoi(argv[1]); // recupere target
	int size = argc - 2;
	
	if (size == 0)
	{
		printf("\n");
		return (0);
	}

	int *set = malloc(sizeof(int) * size);
	if (!set)
		return (1);
	int *cur_subset = malloc(sizeof(int) * size);
	if (!cur_subset)
		return (1);
	
	for (int i = 0 ; i < size ; i++)
		set[i] = atoi(argv[i + 2]); // et stocke tous les autres arguments dans set

	find_solutions(set, cur_subset, target, size, 0, 0, 0);

	free(set);
	free(cur_subset);

	return (0);
}
