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

int	open_one(t_dump *d, char *prog, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, file);
		return (1);
	}
	process_fd(d, fd);
	close(fd);
	return (0);
}

int	run_files(t_dump *d, int argc, char **argv, int *fails)
{
	int	i;
	int	args;

	*fails = 0;
	args = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_dash_c(argv[i]))
		{
			args++;
			*fails += open_one(d, argv[0], argv[i]);
		}
		i++;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_dump	d;
	int		args;
	int		fails;

	init_dump(&d, has_canonical(argc, argv));
	args = run_files(&d, argc, argv, &fails);
	if (args == 0)
	{
		process_fd(&d, 0);
		finish(&d);
		return (0);
	}
	finish(&d);
	if (fails == args)
	{
		write(2, basename(argv[0]), ft_strlen(basename(argv[0])));
		write(2, ": all input file arguments failed\n", 34);
		return (1);
	}
	return (fails > 0);
}
