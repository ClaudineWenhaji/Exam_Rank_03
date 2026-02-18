
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

void print_subset(int *subset, int subset_len, int *found)
{
	*found = 1;
	if (subset_len == 0)
	{
		printf("\n");
		return ;
	}
	int i = 0;
	while (i < subset_len)
	{
		printf("%d", subset[i]);
		if (i < subset_len - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	backtrack(int *nums, int size, int index, int target,
				int *subset, int subset_len, int currrent_sum, int *found)
{
	if (currrent_sum == target && subset_len > 0)
		print_subset(subset, subset_len, found);
	if (index > size)
		return ;
	int i = index;
	while (i < size)
	{
		subset[subset_len] = nums[i];
		backtrack(nums, size, i + 1, target,
				subset, subset_len + 1, currrent_sum + nums[i], found);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	int target = atoi(argv[1]);
	int size = argc - 2;
	int *nums = malloc(sizeof(int) * size);
	if (!nums)
		return (1);
	int i = 0;
	while (i < size)
	{
		nums[i] = atoi(argv[i + 2]);
		i++;
	}
	int *subset = malloc(sizeof(int) * size);
	if (!subset)
	{
		free(nums);
		return (1);
	}
	int found = 0;
	backtrack(nums, size, 0, target,
			subset, 0, 0, &found);
	if (!found)
		printf("\n");
	free(nums);
	free(subset);
	return (0);
}
