#include "get_next_line.h"

char *get_line(int fd, char *line)
{
	char 		*buffer;
	int			size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	size = 1;
	while(!ft_strchr(line,'\n') && size != 0)
	{
		size = read(fd,buffer,BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return NULL;
		}
		buffer[size] = '\0';
		line = ft_strjoin(line,buffer);
	}
	free(buffer);
	return line;
}

char	*save_line(char *get_line)
{
	int counter1;
	int counter2;
	char *saver;

	counter1 = 0;
	counter2 = 0;
	while(get_line[counter1] != '\0' && get_line[counter1] != '\n')
		counter1++;
	if (get_line[counter1] == '\0')
	{
		free(get_line);
		return (0);
	}
	saver = (char *)malloc(sizeof(char) *(ft_strlen(get_line) - counter1 + 1));
	if (saver == NULL)
		return (NULL);
	counter1++;

	while(get_line[counter1] != '\0')
		saver[counter2++] = get_line[counter1++];
	saver[counter2] = '\0';
	free(get_line);
	return saver;
}
char	*read_line(char *get_line)
{
	int counter;
	char *reader;

	counter = 0;
	if(get_line == NULL)
		return NULL;
	while(get_line[counter] != '\0' && get_line[counter] != '\n')
		counter++;
	reader = (char *)malloc(sizeof(char) *(counter + 2));
	if (reader == NULL)
		return (NULL);
	counter = 0;
	while(get_line[counter] != '\0' && get_line[counter] != '\n')
	{
		reader[counter] = get_line[counter];
		counter++;
	}
	if(get_line[counter] == '\n')
		reader[counter++] = '\n';
	reader[counter] = '\0';
	return reader;
}

char *get_next_line(int fd)
{
    static char *next_line;
	char 		*line;

	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_line(fd,next_line);
	if (next_line == NULL)
		return NULL;
	line = read_line(next_line);
	next_line = save_line(next_line);
	if (line[0] == '\0')
	{
		free(next_line);
		free(line);
		return NULL;
	}
    return line;
}
