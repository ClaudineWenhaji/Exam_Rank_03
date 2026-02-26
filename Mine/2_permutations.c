
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	swap(char *a, char *b)
{
	char	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strchr(char *str, char c)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	permutations(char *src, char *res, int pos, int src_len)
{
	int	i = 0;

	if (pos == src_len)
	{
		puts(res);
		return ;
	}
	while (i < src_len)
	{
		if (!ft_strchr(res, src[i]))
		{
			res[pos] = src[i];
			permutations(src, res, pos + 1, src_len);
			res[pos] ='\0';
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	char	*res = calloc(strlen(argv[1]) + 1, sizeof(char));
	if (!res)
		return (1);
	permutations(argv[1], res, 0, strlen(argv[1]));
	free(res);
	return (0);
}
