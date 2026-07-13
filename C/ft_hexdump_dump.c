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

void	dump_canonical(unsigned char *data, int size)
{
	int	off;
	int	star;
	int	n;

	off = 0;
	star = 0;
	while (off < size)
	{
		n = size - off;
		if (n > 16)
			n = 16;
		if (is_repeat(data, off, n))
		{
			if (!star)
				write(1, "*\n", 2);
			star = 1;
		}
		else
		{
			star = 0;
			print_canon_line(data + off, n, off);
		}
		off += n;
	}
}

void	dump_default(unsigned char *data, int size)
{
	int	off;
	int	star;
	int	n;

	off = 0;
	star = 0;
	while (off < size)
	{
		n = size - off;
		if (n > 16)
			n = 16;
		if (is_repeat(data, off, n))
		{
			if (!star)
				write(1, "*\n", 2);
			star = 1;
		}
		else
		{
			star = 0;
			print_default_line(data + off, n, off);
		}
		off += n;
	}
}
