#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1000
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct	variables
{
	int		i;
	int		j;
	char	*ret;
	char	buff[BUFF_SIZE+1];
	char	c;
}				variable;

char	*get_next_line(int fd);
char	*get_next_line_utils(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int	 	slen(const char *str);
char	*ft_strdup(const char *src);
#endif