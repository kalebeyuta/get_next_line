#include "get_next_line.h"

/* concatena duas strings */
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
/*	alocar memoria para s1 afim de retornar nossa resultado caso nossa linha seja nula */
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
/*	alocar o espaço de memoria para que nossa nova string receba o conteudo de 's' em sua totalidade */
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
/*	copiar a primeira string em sua totalidade para nossa nova string */
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
/*	copiar a segunda string em sua totalidade para nossa nova string */
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

/* contar a quantidade de caracteres de uma string */
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
/*	enquanto minha string 's' nao chegar ao fim iremos incrementar nosso conta\
dor 'i' */
	while (s[i] != 0)
		i++;
/*	nosso contador 'i' possui o tamanho de nossa string */
	return (i);
}

/*	apontar em uma string a ultima ocorrencia de um caractere */
char	*ft_strchr(char *line, int c)
{
	size_t	i;

	i = 0;
	if (line == NULL)
		return (0);
/*	caso o caractere que buscamos seja '\0', devemos retornar sua ocorrencia */
	if (c == '\0')
		return ((char *)&line[ft_strlen(line)]);
/*	buscar por nosso caractere passado como parametro e retornar sua ocorrencia dentro de nossa string */
	while (line[i] != '\0')
	{
		if (line[i] == (char)c)
			return ((char *)&line[i]);
		i++;
	}
	return (0);
}

/*	retornar a linha que esta sendo "lida" neste momento */
