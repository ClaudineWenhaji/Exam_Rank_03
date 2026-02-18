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

	if (!str || !arg)
		return (1);
	i = 0;
	while (arg[i])
	{
		if (str[i] != arg[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*buffer;
	int	read_bytes;
	char	*temp;
	int	i;
	size_t	j;
//	size_t	len;	

	if (argc == 2)
	{
		str = malloc(1);
		buffer = malloc(11);
		if (!str || !buffer)
			return (1);
		str[0] = '\0';
//		len = strlen(argv[1]);
		read_bytes = read(0, buffer, 10); // read from stdin in chunks of 10 bytes
		while (read_bytes > 0)		  // concatenate everything into str
		{
			buffer[read_bytes] = 0;
			temp = ft_strjoin(str, buffer);
			free(str);
			str = temp;
			read_bytes = read(0, buffer, 10);
		}
		i = 0;
		while (str[i])			  // replace occurences of argv[1] inside str with *
		{
			if (ft_check(&str[i], argv[1]) == 0)
			{
				j = 0;
//				while (j < len)
				while (j < strlen(argv[1]))
				{
					str[i + j] = '*';
					j++;
				}
			}
			i++;
		}
		printf("%s", str);		  // print result
		free(str);
		free(buffer);
	}
}
