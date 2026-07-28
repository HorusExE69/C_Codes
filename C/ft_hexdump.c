#include "ft_hexdump.h"

int	is_dash_c(char *arg)
{
	if (arg[0] == '-' && arg[1] == 'C' && arg[2] == '\0')
		return (1);
	return (0);
}

int	has_canonical(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_dash_c(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	run_files(t_dump *d, int argc, char **argv)
{
	int	i;
	int	fd;
	int	args;

	args = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_dash_c(argv[i]))
		{
			args++;
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				print_error(argv[0], argv[i]);
			else
			{
				process_fd(d, fd);
				close(fd);
			}
		}
		i++;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_dump	d;
	int		args;

	init_dump(&d, has_canonical(argc, argv));
	args = run_files(&d, argc, argv);
	if (args == 0)
		process_fd(&d, 0);
	finish(&d);
	return (0);
}
