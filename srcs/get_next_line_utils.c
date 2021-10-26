#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	gnl_strchar(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*gnl_strnjoin(char *s1, char *s2, size_t n2)
{
	char	*ary;
	size_t	n1;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	n1 = gnl_strlen(s1);
	ary = malloc(n1 + n2 + 1);
	if (ary == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		ary[i++] = s1[j++];
	j = 0;
	while (j < n2)
		ary[i++] = s2[j++];
	ary[i] = '\0';
	return (ary);
}

char	*gnl_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	s2 = malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
