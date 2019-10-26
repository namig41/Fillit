#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE	5
# if BUFF_SIZE < 0
#  error "BUFF_SIZE has wrong size"
# endif
# define SEPARATOR '\n'
# define MAX_FILES	100000
# define MEM_ERR -1

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int			get_next_line(const int fd, char **line);

#endif