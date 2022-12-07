#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
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
	int		bytes;
	int		k;
}				variable;

char	*get_next_line(int fd);
char	*read_buffer(int fd, variable var, char *holder);
char	*get_line(variable var, char *holder);
char	*update_holder(variable var, char *holder);
char	*get_next_line_utils(int fd);
int	 	slen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
#endif