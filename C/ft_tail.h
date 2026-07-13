#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	copy_bytes(char *dst, char *src, int n);
void	print_error(char *prog, char *file);
char	*read_file(int fd, int *size);
void	print_header(char *file, int mode);
void	print_tail(char *data, int size, int nbytes);
void	process_file(char *prog, char *file, int nbytes, int mode);
void	process_stdin(int nbytes);

#endif
