#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

//char	*add_to_holder(int fd, variable var, char holder);

char	*return_from_holder(variable var, char *holder)
{
	var.i = 0;
	var.j = 0;
	var.buff = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	while (holder[var.i] != '\0')
	{
		var.i++;
		if (holder[var.i] == '\n')
		{
			var.ret = (char *) malloc (sizeof(char) * var.i + 1);
			while (var.i-- > 0)
				var.ret[var.j++] = *holder++;
			var.ret[var.j] = '\0';
			var.temp = (char *) malloc (sizeof(char) * slen(holder) + 1);
			while (holder[var.i] != '\0')
				var.temp[var.i++] = holder[var.i++];
			var.temp[var.i] = '\0';
			free(holder);
			holder = (char *) malloc (sizeof(char) * slen(var.temp) + 1);
			var.i = 0;
			while (*var.temp != '\0')
				holder[var.i++] = *var.temp++;
			free(var.temp);
			return (var.ret);
		}
	}
	return (var.ret);
}

char	*get_line(int fd, variable var, char *holder)
{
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
				return (return_from_holder(var, holder));
			}
	//	else
	//			add_to_holder(fd, var, holder);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	variable	var;
	static char	*holder;

	var.i = 0;
	var.j = 0;
	var.ret = NULL;
	if (fd == -1 || !fd || !var.buff)
		return (NULL);
	if (holder)
	{
		var.ret = return_from_holder(var, holder);
		return var.ret;
	}
		var.ret = get_line(fd, var, holder);
		return var.ret;
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int i;

	i = 0;

	while (i++ < 3)
		printf("%s", get_next_line(fd));

	return(0);
}
