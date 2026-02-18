
#include "gnl.h"

int ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int	len = ft_strlen(str);
	int	i = 0;
	char *copy = malloc(sizeof(char) * (len + 1));

	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];// a resuable chunk of memeory (size(BUFFER_SIZE) where you read from the file )
	static int buffer_i; // the index of the next byte in buf to consume;
	static int buffer_len; // how many bytes are currently in buf (result of last read)
	int			i = 0; // how many characters you've put into line so far
	char		line[70000]; a temporary local array where you assemble one output line.
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_i >= buffer_len)
		{
			buffer_len = read(fd, buf, BUFFER_SIZE);
			buffer_i = 0;
			if (buffer_len <= 0)
				break;
		}
		line[i] = buf[buffer_i];
		i++;
		buffer_i++;
		if (line[i - 1] == '\n')
			break;
	}
	if (i == 0) // If you didn’t copy any bytes (i == 0), you return NULL (means: nothing more to read).
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}
/*
int	main()
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL )
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
