#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 42

char *ft_filter(char *src, char *target)
{
	int i = 0;
	int target_i = 0;
	int n = 0;

	while(src[i])
	{
		if (src[i] == target[0])
		{
			while (src[i+target_i] && target[target_i] && src[i+target_i] == target[target_i])
			{
				target_i++;
			}
			if (target[target_i] == 0)
			{
				while (n < target_i)
				{
					write(1,"*", 1);
					n++;
				}
				i += n;
				n = 0;
				target_i = 0;
			}
			else
			{
				write(1,&src[i], 1);
				i++;
				n = 0;
				target_i = 0;
			}
		}
		else
		{
			write(1,&src[i], 1);
			i++;
			n = 0;
			target_i = 0;
		}
	}
}

char *read_stdin(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index = 0;
	static int buffer_size = 0;
	int i = 0;
	char *line = malloc (10000);
	
	if (!line)
		return(write(2, "Error: ", 7), perror("malloc"), NULL);
	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_index = 0;
			buffer_size = read(0, buffer, BUFFER_SIZE);
			if (buffer_size < 0)
			{
				free(line);
				return(write(2, "Error: ", 7), perror("read"), NULL);
			}
			if (buffer_size == 0)
				break;
		}
		line[i] = buffer[buffer_index];
		i++;
		buffer_index++;
	}
	line[i] = 0;
	return (line);
}

int main(int argc, char **argv)
{
	char *line;

	if (argc != 2 || argv[1][0] == 0)
		return 1;
	line = read_stdin();
	if (!line)
		return 1;
	ft_filter(line, argv[1]);
	free(line);
	return 0;
}
