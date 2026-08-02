#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_opts
{
	long	nbytes;
	int		nfiles;
	int		err;
	char	*bad;
}	t_opts;

int		ft_strlen(char *str);
char	*ft_basename(char *path);
void	copy_bytes(char *dst, char *src, int n);
void	print_open_error(char *prog, char *file);
void	print_read_error(char *prog, char *file);
char	*read_file(int fd, int *size, int *rerr);
void	print_header(char *file, int *printed);
void	print_tail(char *data, int size, long nbytes);
int		is_c_flag(char *arg);
int		is_c_attached(char *arg);
int		parse_number(char *s, long *out);
void	init_opts(t_opts *o);
void	handle_value(t_opts *o, char *arg);
void	parse_args(int argc, char **argv, t_opts *o);
void	print_opt_error(char *prog, t_opts *o);
int		process_file(char *prog, char *file, long nbytes, int *printed);
int		process_all(int argc, char **argv, long nbytes, int nfiles);

#endif
