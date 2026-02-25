#ifndef GNL_H
# define GNL_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char    *ft_strdup(char *str);
char    *get_next_line(int fd);

#endif

