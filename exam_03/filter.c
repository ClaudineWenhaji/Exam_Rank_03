
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] =((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*read_stdin(void)
{
	char	*buf = NULL;
	char	tmp[BUFFER_SIZE];
	ssize_t	bytes;
	size_t	total = 0;
	while ((bytes = read(0, tmp, BUFFER_SIZE)) > 0)
	{
		char	*new_buff = realloc(buf, total + bytes + 1);
		if (!new_buff)
		{
			write(2, "Error: ", 7);
			perror("malloc/realloc");
			free(buf);
			return (NULL);
		}
		buf = new_buff;
		ft_memcpy(buf + total, tmp, bytes);
		total = total + bytes;
	}
	if (bytes < 0)
	{
		write(2, "Error: ", 7);
		perror("read");
		free(buf);
		return (NULL);
	}
	if (buf)
		buf[total] = '\0';
	return (buf);
}

int	match_at(char *str, int i, char *s)
{
	int	j = 0;
	while (s[j] && str[i + j] && str[i + j] == s[j])
		j++;
	return (s[j] == '\0');
}

void	replace_and_print(char *input, char *s)
{
	size_t i = 0;
	size_t len = strlen(s);
	if (len == 0)
		return ;
	while (input[i])
	{
		if (match_at(input, i, s))
		{
			size_t k = 0;
			while (k < len)
			{
				write(1, "*", 1);
				k++;
			}
			i = i + len;
		}
		else
		{
			write(1, &input[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char	*s = argv[1];
	if (!s[0])
		return 1;
	char	*input = read_stdin();
	if (!input)
		return 1;
	replace_and_print(input, s);
	free(input);
	return (0);
}