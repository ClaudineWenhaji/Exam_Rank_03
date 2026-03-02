/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:22:22 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/03/02 15:50:36 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	sort_string(char *str)
{
	int	i = 0;
	int	j;
	char	tmp;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
				tmp = str[j];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_strchr(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	permutation(char *str, char *res, int pos, int len)
{
	if (pos == len)
	{
		puts(res);
		return ;
	}
	int i = 0;
	while (i < len)
	{
		if (!ft_strchr(res, str[i]))
		{
			res[pos] = str[i];
			permutation(str, res, pos + 1, len);
			res[pos] = '\0';
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *res;
	int len = strlen(av[1]);
	res = malloc(sizeof(char) * len);
	if (!res)
		return (1);
	res[0] = 0;
	sort_string(av[1]);
	permutation(av[1], res, 0, len);
	free(res);
	return (0);
}
