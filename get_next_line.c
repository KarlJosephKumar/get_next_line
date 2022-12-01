#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*update_holder(variable var, char *holder)
{
	int k;
	
	k = slen(holder);
	while(*holder++ != '\n')
		var.i++;
	var.temp = (char *) malloc (sizeof(char) * slen(holder) + 1 - var.i);
	if (var.temp == 0)
		return holder -1;
	if (!var.temp)
		return (NULL);
	var.i = 0;
	while (*holder != '\0')
		var.temp[var.i++] = *holder++;
	var.temp[var.i++] = '\n';
	var.temp[var.i] = '\0';
	free(holder-k);
	holder = (char *) malloc (sizeof(char) * slen(var.temp) + 1);
	var.i = 0;
	while (*var.temp != '\0')
		holder[var.i++] = *var.temp++;
	free(var.temp-var.i);
	return (holder);
}

char	*return_from_holder(variable var, char *holder)
{
	var.i = 0;
	var.j = 0;
	while (holder[var.i] != '\0')
	{
		if (holder[var.i] == '\n')
		{
			var.ret = (char *) malloc (sizeof(char) * var.i + 1);
			while (*holder != '\n')
				var.ret[var.j++] = *holder++;
			var.ret[var.j++] = '\n';
			var.ret[var.j] = '\0';
			return (var.ret);
		}
		var.i++;
	}
	return (var.ret);
}

char	*get_line(int fd, variable var)
{
	static char	*holder;

	while(read(fd, var.buff, BUFFER_SIZE) != 0)
	{
		var.i = 0;
		while (var.i < BUFFER_SIZE)
		{
			var.i++;
			if (var.buff[var.i] == '\n')
			{
				holder = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
				while(var.j < BUFFER_SIZE)
					holder[var.j++] = var.buff[var.j];
				holder[var.j] = '\0';
				free(var.buff);
				var.ret = return_from_holder(var, holder);
				return (var.ret);
			}
		}
	}
	if (holder != NULL)
	{
		holder = update_holder(var, holder);
		var.ret = return_from_holder(var, holder);
		return var.ret;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	variable	var;

	var.i = 0;
	var.j = 0;
	var.ret = NULL;
	var.buff = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (fd == -1 || !fd || !var.buff)
		return (NULL);
	var.ret = get_line(fd, var);
	return var.ret;
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int i;

	i = 0;

	while (i++ < 4)
		printf("%s", get_next_line(fd));

	return(0);
}
