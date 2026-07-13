#include "ft_hexdump.h"

void	put_hex(unsigned int n, int width)
{
	char	*base;
	char	buf[16];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (i < width)
	{
		buf[i] = base[(n >> ((width - 1 - i) * 4)) & 0xf];
		i++;
	}
	write(1, buf, width);
}

void	copy_bytes(unsigned char *dst, unsigned char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

unsigned char	*append_fd(int fd, unsigned char *data, int *size)
{
	unsigned char	buffer[4096];
	unsigned char	*tmp;
	int				ret;

	ret = read(fd, buffer, 4096);
	while (ret > 0)
	{
		tmp = malloc(*size + ret);
		if (!tmp)
		{
			free(data);
			return (NULL);
		}
		copy_bytes(tmp, data, *size);
		copy_bytes(tmp + *size, buffer, ret);
		free(data);
		data = tmp;
		*size += ret;
		ret = read(fd, buffer, 4096);
	}
	return (data);
}

int	lines_equal(unsigned char *a, unsigned char *b)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_repeat(unsigned char *data, int off, int n)
{
	if (off >= 16 && n == 16 && lines_equal(data + off, data + off - 16))
		return (1);
	return (0);
}
