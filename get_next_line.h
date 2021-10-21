#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H
# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif
#include<unistd.h>
#include<stdlib.h>
char	*ft_strchr(char *src, int c);
int	    ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);
char    *get_line(int fd, char *line);
char	*read_line(char *get_line);
char	*save_line(char *get_line);
#endif