#include "get_next_line.h"

int slen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while(str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = slen(src);
	ptr = (char*)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}