#include "ft_tail.h"

void	process_file(char *prog, char *file, int nbytes, int mode)
{
	int		fd;
	int		size;
	char	*data;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, file);
		return ;
	}
	data = read_file(fd, &size);
	close(fd);
	print_header(file, mode);
	print_tail(data, size, nbytes);
	free(data);
}

void	process_stdin(int nbytes)
{
	int		size;
	char	*data;

	data = read_file(0, &size);
	print_tail(data, size, nbytes);
	free(data);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nbytes;
	int	mode;

	if (argc < 3 || argv[1][0] != '-' || argv[1][1] != 'c' || argv[1][2])
		return (0);
	nbytes = ft_atoi(argv[2]);
	if (argc == 3)
	{
		process_stdin(nbytes);
		return (0);
	}
	if (argc == 4)
		mode = 0;
	else
		mode = 1;
	i = 3;
	while (i < argc)
	{
		process_file(basename(argv[0]), argv[i], nbytes, mode);
		if (mode != 0)
			mode = 2;
		i++;
	}
	return (0);
}
