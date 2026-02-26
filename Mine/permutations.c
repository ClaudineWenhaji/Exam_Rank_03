/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:24:22 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/26 18:26:32 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutations.h"

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

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
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
void	swap(char *a, char *b)
{
	char	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}*/

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

/*
src: la string originale
res: la permutation en train d'etre construite
pos: position actuelle a remplir dans res
src_len: longueur de src

On construit la permutation caractere par caractere
puis on revient en arriere (backtracking) pour tester d'autres possibilites)
*/

void	permutations(char *src, char *res, int pos, int src_len)
{
	int	i = 0;

	if (pos == src_len) // Condition d'arret
	{
		puts(res);
		return ;
	}
	while (i < src_len) // on parcourt toutes les lettres de src
	{
		if (!ft_strchr(res, src[i])) // on evite les doublons
					     // en verifiant si la lettre a deja ete utilisee dans res
					     // si oui, on ignore, sinon on peut l'ajouter
		{
			res[pos] = src[i];   			  // on ajoute
			permutations(src, res, pos + 1, src_len); // on passe a la position suivante
			res[pos] ='\0'; 			  // on efface la lettre quon avait mise pour tester d'autres possibilites
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*res;
	int	len = 0;

	if (ac != 2)
		return (1);

	len = ft_strlen(av[1]);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (1);
	res[0] = 0; // string vide au depart
	sort_string(av[1]);
	permutations(av[1], res, 0, len);
	free(res);
	return (0);
}
