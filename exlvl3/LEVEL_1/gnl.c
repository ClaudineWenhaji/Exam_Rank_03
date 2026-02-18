#include <fcntl.h>    
#include <unistd.h>   
#include <stdlib.h>   
#include <stdio.h>    

#define BUFFER_SIZE 1024

char *ft_strdup(char *src)
{
    int i = 0;
    int len = 0;
    char *dest;

    while (src[len])
        len++;
    dest = malloc(len + 1);
    if (!dest)
        return (NULL);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}


char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_i = 0;
    static int buffer_size = 0;
    char line[70000];
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_i >= buffer_size)
        {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            buffer_i = 0;
            if (buffer_size <= 0)
                break;
        }
        line[i] = buffer[buffer_i];
        i++;
        buffer_i++;
        if (line[i - 1] == '\n')
            break;
    }
    if (i == 0)
        return (NULL);
    line[i] = '\0';
    return (ft_strdup(line));
}

int main(void)
{
    int fd;
    char *str;

    fd = open("text.txt", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }
    close(fd);
    return (0);
}
