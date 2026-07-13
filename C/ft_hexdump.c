#include "ft_hexdump.h"

int	is_dash_c(char *arg)
{
	if (arg[0] == '-' && arg[1] == 'C' && arg[2] == '\0')
		return (1);
	return (0);
}

unsigned char	*read_input(int argc, char **argv, int start, int *size)
{
	unsigned char	*data;
	int				i;
	int				fd;

	*size = 0;
	data = NULL;
	if (start >= argc)
		return (append_fd(0, data, size));
	i = start;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd >= 0)
		{
			data = append_fd(fd, data, size);
			close(fd);
		}
		i++;
	}
	return (data);
}

void	dump(unsigned char *data, int size, int canonical)
{
	if (canonical)
		dump_canonical(data, size);
	else
		dump_default(data, size);
	if (size <= 0)
		return ;
	if (canonical)
		put_hex(size, 8);
	else
		put_hex(size, 7);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	unsigned char	*data;
	int				size;
	int				canonical;
	int				start;

	canonical = 0;
	start = 1;
	if (argc > 1 && is_dash_c(argv[1]))
	{
		canonical = 1;
		start = 2;
	}
	data = read_input(argc, argv, start, &size);
	dump(data, size, canonical);
	free(data);
	return (0);
}
