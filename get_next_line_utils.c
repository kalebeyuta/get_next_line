#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	int		length1;
	int		length2;
	char	*joined;

	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (length1 + length2) + 1);
	if (joined == NULL)
	return (NULL);

	counter = 0;
	while (s1[counter])
	{
		joined[counter] = s1[counter];
		counter++;
	}
	counter = 0;
	while (s2[counter])
	{
		joined[length1 + counter] = s2[counter];
		counter++;
	}
	joined[length1 + counter] = '\0';
	return (joined);
}

int	ft_strlen(const char *str)
{
	int		cont;

	cont = 0;
	while (*str)
	{
		str++;
		cont++;
	}
	return (cont);
}
char	*ft_strchr(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
/*	caso o caractere que buscamos seja '\0', devemos retornar sua ocorrencia */
	if (c == '\0')
		return ((char *)&src[ft_strlen(src)]);
/*	buscar por nosso caractere passado como parametro e retornar sua ocorrencia dentro de nossa string */
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}
