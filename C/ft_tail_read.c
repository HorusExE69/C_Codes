#include "ft_tail.h"

char	*ft_basename(char *path)
{
	char	*base;
	int		i;

	base = path;
	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			base = path + i + 1;
		i++;
	}
	return (base);
}

static char	*grow(char *data, int size, char *buf, int ret)
{
	char	*tmp;

	tmp = malloc(size + ret);
	if (!tmp)
	{
		free(data);
		return (NULL);
	}
	copy_bytes(tmp, data, size);
	copy_bytes(tmp + size, buf, ret);
	free(data);
	return (tmp);
}

char	*read_file(int fd, int *size, int *rerr)
{
	char	buffer[4096];
	char	*data;
	int		ret;

	*size = 0;
	*rerr = 0;
	data = NULL;
	ret = read(fd, buffer, 4096);
	while (ret > 0)
	{
		data = grow(data, *size, buffer, ret);
		if (!data)
			return (NULL);
		*size += ret;
		ret = read(fd, buffer, 4096);
	}
	if (ret < 0)
		*rerr = 1;
	return (data);
}

void	print_header(char *file, int *printed)
{
	if (*printed < 0)
		return ;
	if (*printed == 1)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, file, ft_strlen(file));
	write(1, " <==\n", 5);
	*printed = 1;
}

void	print_tail(char *data, int size, long nbytes)
{
	long	start;

	if (nbytes >= size)
		start = 0;
	else
		start = size - nbytes;
	if (data && nbytes > 0)
		write(1, data + start, size - start);
}
