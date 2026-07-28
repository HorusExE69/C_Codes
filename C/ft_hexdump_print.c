#include "ft_hexdump.h"

void	print_ascii(unsigned char *line, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = line[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_canon_line(unsigned char *line, int n, unsigned int off)
{
	int	i;

	put_hex(off, 8);
	write(1, "  ", 2);
	i = 0;
	while (i < 16)
	{
		if (i == 8)
			write(1, " ", 1);
		if (i < n)
		{
			put_hex(line[i], 2);
			write(1, " ", 1);
		}
		else
			write(1, "   ", 3);
		i++;
	}
	write(1, " |", 2);
	print_ascii(line, n);
	write(1, "|\n", 2);
}

void	print_default_line(unsigned char *line, int n, unsigned int off)
{
	int				i;
	unsigned int	word;

	put_hex(off, 7);
	i = 0;
	while (i < n)
	{
		word = line[i];
		if (i + 1 < n)
			word = word | (line[i + 1] << 8);
		write(1, " ", 1);
		put_hex(word, 4);
		i += 2;
	}
	while (i < 16)
	{
		write(1, "     ", 5);
		i += 2;
	}
	write(1, "\n", 1);
}

void	print_line(t_dump *d, int n)
{
	if (d->canonical)
		print_canon_line(d->line, n, d->offset);
	else
		print_default_line(d->line, n, d->offset);
}

void	print_error(char *prog, char *file)
{
	write(2, basename(prog), ft_strlen(basename(prog)));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}
