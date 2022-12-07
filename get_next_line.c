#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


char	*ft_join(char *buff, char *holder)
{
	char	*temp;

	if(!holder)
	{
		holder = malloc(1);
		*holder = '\0';
	}
	temp = ft_strjoin(holder, buff);
	free(buff);
	return (temp);
}

char	*update_holder(variable var, char *holder)
{
	var.k = slen(holder);
	var.i = 0;
	while(holder[var.i] != '\n' && var.i < var.k)
		var.i++;
	if(holder[var.i] == '\n')
		var.i++;
	var.temp = (char *) malloc (sizeof(char) * slen(holder) - var.i + 1);
	if (!var.temp)
		return (NULL);
	while (holder[var.i] != '\0')
		var.temp[var.j++] = holder[var.i++];
	var.temp[var.j] = '\0';
	free(holder);
	holder = (char *) malloc (sizeof(char) * slen(var.temp) + 1);
	var.i = 0;
	while (var.temp[var.i] != '\0')
		holder[var.i++] = var.temp[var.i];
	holder[var.i] = '\0';
	free(var.temp);
	return (holder);
}

char	*get_line(variable var, char *holder)
{
	var.i = 0;
	var.j = 0;
	if (holder[var.i] == '\0')
	{
		free(holder);
		return (NULL);
	}
	while (holder[var.i] != '\0')
	{
		if (holder[var.i] == '\n')
		{
			var.ret = (char *) malloc (sizeof(char) * var.i + 2);
			if (!var.ret)
			{
				free(holder);
				return (NULL);
			}
			while (holder[var.j] != '\n')
				var.ret[var.j++] = holder[var.j];
			var.ret[var.j++] = '\n';
			var.ret[var.j] = '\0';
			return (var.ret);
		}
		var.i++;
	}
	return (var.ret);
}

char	*read_buffer(int fd, variable var, char *holder)
{
	var.bytes = 1;
	while (var.bytes > 0)
	{
		var.buff = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
		if (var.buff == NULL)
			return (NULL);
		var.bytes = read(fd, var.buff, BUFFER_SIZE);
		if (var.bytes < 0)
		{
			free(var.buff);
			return (NULL);
		}
		var.buff[var.bytes] = '\0'; 
		if (ft_strchr(var.buff, '\n') == NULL)
			holder = ft_join(var.buff, holder);
		else
		{
			holder = ft_join(var.buff, holder);
			break ;
		}
	}
	return (holder);
}

char	*get_next_line(int fd)
{
	variable	var;
	static char	*holder;
	
	var.i = 0;
	var.j = 0;
	if (fd < 0 || !fd || read(fd, 0, 0) < 0)
		return (NULL);
	if (!holder || ft_strchr(holder, '\n') == NULL)
		holder = read_buffer(fd, var, holder);
	if (holder[var.i] == '\0')
	{
		free(holder);
		return (NULL);
	}
	if (holder && ft_strchr(holder, '\n') == NULL)
	{
		var.ret = (char *) malloc (sizeof(char) * slen(holder) + 1);
		while (holder[var.i] != '\0')
			var.ret[var.i++] = holder[var.i];
		var.ret[var.i] = '\0';
		holder = update_holder(var, holder);
		free(holder);
		return (var.ret);
	}
	else
		var.ret = get_line(var, holder);
	if (var.ret && holder[var.i] != '\0')
		holder = update_holder(var, holder);
	else if (holder[var.i] == '\0')
		return (NULL);
	return (var.ret);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int i;

// 	i = 0;

// 	while (i++ < 3)
// 		printf("%s", get_next_line(fd));

// 	return(0);
// }
