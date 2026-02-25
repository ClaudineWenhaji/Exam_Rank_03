/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:56 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/02/25 14:43:12 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strdup(char *str)
{
	int	i = 0;
	int	len = 0;
	char	*dup;

	while (str[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_i = 0;
	static int	buffer_size = 0;;
	int		i = 0;
	char		line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_i >= buffer_size)	// tout ce quon avait lu a ete consomme
		{
			buffer_i = 0;				// on remet a 0 pour relire depuis le debut du fichier
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)		// on quitte la boucle si read echoue (-1) ou read revoie 0 (fin du fichier)
				break ;
		}
		line[i] = buffer[buffer_i]; 	// copie caractere / caractere du buffer dans line
		i++;
		buffer_i++;
		if (line[i - 1] == '\n')		// on arrete des quon rencontre \n
			break ;
	}
	if (i == 0)							// si aucun caractere lu i.e fin du fichier
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));			// renvoie une copie dynamique de la ligne
}

int	main(int ac, char **av)
{
	char	*line;
	int	fd = 0;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Line %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
