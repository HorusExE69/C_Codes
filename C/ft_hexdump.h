#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void			put_hex(unsigned int n, int width);
void			copy_bytes(unsigned char *dst, unsigned char *src, int n);
unsigned char	*append_fd(int fd, unsigned char *data, int *size);
int				lines_equal(unsigned char *a, unsigned char *b);
int				is_repeat(unsigned char *data, int off, int n);
void			print_ascii(unsigned char *line, int n);
void			print_canon_line(unsigned char *line, int n, unsigned int off);
void			print_default_line(unsigned char *line, int n, unsigned int off);
void			dump_canonical(unsigned char *data, int size);
void			dump_default(unsigned char *data, int size);
void			dump(unsigned char *data, int size, int canonical);
unsigned char	*read_input(int argc, char **argv, int start, int *size);
int				is_dash_c(char *arg);

#endif
