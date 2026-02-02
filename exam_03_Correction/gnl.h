
#ifndef GNL_H
#define GNL_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>  // open, o_rdonly
#include <stddef.h> //size_t

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char 	*get_next_line(int fd);

#endif
