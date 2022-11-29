#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*get_line(int fd, variable var)
{
	while (read(fd, &var.c, 1))
	{
		if(var.c == '\n')
		{
			var.buff[var.i++] = var.c;
			var.buff[var.i] = '\0';
			break;
		}
		if (var.i == BUFF_SIZE && var.c != '\n')
		{
			var.buff[var.i] = var.c;
			var.buff[var.i+1] = '\0';
			if(var.ret == NULL)
				var.ret = ft_strdup(var.buff);
			else
				var.ret = ft_strjoin((const char *)var.ret, (const char *)var.buff);
			var.i = 0;
			read(fd, &var.c, 1);
		}
		var.buff[var.i++] = var.c;
	}
	if(var.ret == NULL)
		var.ret = ft_strdup((const char *)var.buff);
	else
		var.ret = ft_strjoin((const char *)var.ret, (const char *)var.buff);
	return var.ret;
}

char	*get_next_line(int fd)
{
	variable var;

	var.i = 0;
	var.j = 0;
	var.ret = NULL;
	if (fd == -1)
		return (NULL);
	var.ret = get_line(fd, var);
	return var.ret;
}

// int main(void)
// {
// 	int fd = open("test1.txt", O_RDONLY);
// 	int i;

// 	i = 0;
// 	while (i++ < 9)
// 		printf("%s", get_next_line(fd));

// 	return(0);
// }