#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct	variables
{
	int		i;
	int		j;
	char	*ret;
	char	*buff;
	char	*temp;
}				variable;

char	*get_next_line(int fd);
char	*get_line(int fd, variable var, char *holder);
char	*return_from_holder(variable var, char *holder);
char	*get_next_line_utils(int fd);
int	 	slen(char *str);
char	*ft_strdup(char *src);
#endif