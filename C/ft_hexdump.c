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
	int	r;
	int	err;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, file);
		return (1);
	}
	r = process_fd(d, fd);
	err = errno;
	close(fd);
	if (r)
	{
		errno = err;
		print_error(prog, file);
		return (2);
	}
	return (0);
}

void	run_files(t_dump *d, int argc, char **argv, t_stat *st)
{
	int	i;
	int	r;

	st->nargs = 0;
	st->openfails = 0;
	st->anyerr = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_dash_c(argv[i]))
		{
			st->nargs++;
			r = open_one(d, argv[0], argv[i]);
			if (r == 1)
				st->openfails++;
			if (r != 0)
				st->anyerr = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dump	d;
	t_stat	st;

	init_dump(&d, has_canonical(argc, argv));
	run_files(&d, argc, argv, &st);
	if (st.nargs == 0)
	{
		process_fd(&d, 0);
		finish(&d);
		return (0);
	}
	finish(&d);
	if (st.openfails == st.nargs)
	{
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": all input file arguments failed\n", 34);
		return (1);
	}
	return (st.anyerr != 0);
}
