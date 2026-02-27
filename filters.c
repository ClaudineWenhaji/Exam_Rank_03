#include <stdlib.h>     // malloc, free
#include <unistd.h>     // read
#include <stdio.h>      // printf
#include <string.h>     // strlen

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_check(char *str, char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (str[i] != arg[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*str;
	char	*buffer;
	int	buffer_size;
	char	*temp;
	int	i;
	size_t	j;

	if (ac == 2)
	{
		str = malloc(70000);
		buffer = malloc(70000);
		buffer_size = read(0, buffer, 10); 	  // read from stdin in chunks of 10 bytes
		while (buffer_size > 0)		 	  // concatenate everything into str, on lit jusqua la fin de lentree
		{
			buffer[buffer_size] = 0;	  // Termine buffer par un \0 pour en faire une chaîne C
			temp = ft_strjoin(str, buffer); // On concatène progressivement tout le contenu lu dans str.
			free(str);
			str = temp;
			buffer_size = read(0, buffer, 10);
		}
		i = 0;
		while (str[i])				 // replace occurences of av[1] inside str with *
		{
			if (ft_check(&str[i], av[1]) == 0)
			{
				j = 0;
				while (j < strlen(av[1]))
				{
					str[i + j] = '*';
					j++;
				}
			}
			i++;
		}
		printf("%s", str);		  // print result
	}
}
