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

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (a == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = slen((char *) s1);
	len2 = slen((char *) s2);
	i = 0;
	joined = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	while (len1-- > 0)
		joined[i++] = *s1++;
	while (len2-- > 0)
		joined[i++] = *s2++;
	joined[i] = '\0';
	return (joined);
}

