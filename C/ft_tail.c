#include "ft_tail.h"

void	parse_args(int argc, char **argv, t_opts *o)
{
	int	i;

	init_opts(o);
	i = 1;
	while (i < argc && o->err == 0)
	{
		if (is_c_flag(argv[i]))
		{
			i++;
			if (i >= argc)
				o->err = 1;
			else
				handle_value(o, argv[i]);
		}
		else if (is_c_attached(argv[i]))
			handle_value(o, argv[i] + 2);
		else
			o->nfiles++;
		i++;
	}
}

void	print_opt_error(char *prog, t_opts *o)
{
	write(2, prog, ft_strlen(prog));
	if (o->err == 1)
	{
		write(2, ": option requires an argument -- 'c'\n", 37);
		write(2, "Try '", 5);
		write(2, prog, ft_strlen(prog));
		write(2, " --help' for more information.\n", 31);
		return ;
	}
	write(2, ": invalid number of bytes: ", 27);
	write(2, "\xe2\x80\x98", 3);
	write(2, o->bad, ft_strlen(o->bad));
	write(2, "\xe2\x80\x99", 3);
	if (o->err == 3)
		write(2, ": Value too large for defined data type", 39);
	write(2, "\n", 1);
}

int	process_file(char *prog, char *file, long nbytes, int mode)
{
	int		fd;
	int		size;
	int		rerr;
	char	*data;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_open_error(prog, file);
		return (1);
	}
	print_header(file, mode);
	data = read_file(fd, &size, &rerr);
	close(fd);
	if (rerr)
	{
		print_read_error(prog, file);
		free(data);
		return (1);
	}
	print_tail(data, size, nbytes);
	free(data);
	return (0);
}

int	process_all(int argc, char **argv, long nbytes, int nfiles)
{
	int	i;
	int	idx;
	int	fails;

	idx = 0;
	fails = 0;
	i = 1;
	while (i < argc)
	{
		if (is_c_flag(argv[i]))
			i += 2;
		else if (is_c_attached(argv[i]))
			i += 1;
		else
		{
			fails += process_file(argv[0], argv[i], nbytes,
					get_mode(nfiles, idx));
			idx++;
			i += 1;
		}
	}
	return (fails);
}

int	main(int argc, char **argv)
{
	t_opts	o;
	int		fails;

	parse_args(argc, argv, &o);
	if (o.err != 0)
	{
		print_opt_error(argv[0], &o);
		return (1);
	}
	if (o.nfiles == 0)
		return (0);
	fails = process_all(argc, argv, o.nbytes, o.nfiles);
	if (fails > 0)
		return (1);
	return (0);
}
