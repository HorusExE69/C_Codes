#include "ft_hexdump.h"

void	init_dump(t_dump *d, int canonical)
{
	d->fill = 0;
	d->offset = 0;
	d->has_prev = 0;
	d->star = 0;
	d->canonical = canonical;
}

void	flush_full(t_dump *d)
{
	if (d->has_prev && lines_equal(d->line, d->prev))
	{
		if (!d->star)
			write(1, "*\n", 2);
		d->star = 1;
	}
	else
	{
		d->star = 0;
		print_line(d, 16);
	}
	copy16(d->prev, d->line);
	d->has_prev = 1;
	d->offset += 16;
	d->fill = 0;
}

void	feed(t_dump *d, unsigned char c)
{
	d->line[d->fill] = c;
	d->fill++;
	if (d->fill == 16)
		flush_full(d);
}

void	finish(t_dump *d)
{
	if (d->fill > 0)
	{
		print_line(d, d->fill);
		d->offset += d->fill;
		d->fill = 0;
	}
	if (d->offset <= 0)
		return ;
	if (d->canonical)
		put_hex(d->offset, 8);
	else
		put_hex(d->offset, 7);
	write(1, "\n", 1);
}

int	process_fd(t_dump *d, int fd)
{
	unsigned char	buffer[4096];
	int				ret;
	int				i;

	ret = read(fd, buffer, 4096);
	while (ret > 0)
	{
		i = 0;
		while (i < ret)
		{
			feed(d, buffer[i]);
			i++;
		}
		ret = read(fd, buffer, 4096);
	}
	return (ret < 0);
}
