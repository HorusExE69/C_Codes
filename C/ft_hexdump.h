#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

typedef struct s_dump
{
	unsigned char	line[16];
	unsigned char	prev[16];
	int				fill;
	int				offset;
	int				has_prev;
	int				star;
	int				canonical;
}	t_dump;

typedef struct s_stat
{
	int	nargs;
	int	openfails;
	int	anyerr;
}	t_stat;

void	put_hex(unsigned int n, int width);
int		ft_strlen(char *str);
int		lines_equal(unsigned char *a, unsigned char *b);
void	copy16(unsigned char *dst, unsigned char *src);
void	print_ascii(unsigned char *line, int n);
void	print_canon_line(unsigned char *line, int n, unsigned int off);
void	print_default_line(unsigned char *line, int n, unsigned int off);
void	print_line(t_dump *d, int n);
void	print_error(char *prog, char *file);
void	init_dump(t_dump *d, int canonical);
void	feed(t_dump *d, unsigned char c);
void	flush_full(t_dump *d);
void	finish(t_dump *d);
int		process_fd(t_dump *d, int fd);
int		is_dash_c(char *arg);
int		has_canonical(int argc, char **argv);
int		open_one(t_dump *d, char *prog, char *file);
void	run_files(t_dump *d, int argc, char **argv, t_stat *st);

#endif
