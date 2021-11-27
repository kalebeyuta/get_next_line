#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H
# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif
#include<unistd.h>
#include<stdlib.h>
char	*ft_strchr(char *line, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char    *get_line(int fd, char *line);
char	*read_line(char *get_line);
char	*save_line(char *get_line);
#endif