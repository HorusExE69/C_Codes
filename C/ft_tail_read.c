#include "ft_tail.h"

char	*read_file(int fd, int *size)
{
	char	buffer[4096];
	char	*data;
	char	*tmp;
	int		ret;

	*size = 0;
	data = NULL;
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

void	print_header(char *file, int mode)
{
	if (mode == 0)
		return ;
	if (mode == 2)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, file, ft_strlen(file));
	write(1, " <==\n", 5);
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
