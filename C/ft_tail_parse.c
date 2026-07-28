#include "ft_tail.h"

int	is_c_flag(char *arg)
{
	if (arg[0] == '-' && arg[1] == 'c' && arg[2] == '\0')
		return (1);
	return (0);
}

int	is_c_attached(char *arg)
{
	if (arg[0] == '-' && arg[1] == 'c' && arg[2] != '\0')
		return (1);
	return (0);
}

int	parse_args(int argc, char **argv, int *nbytes, int *nfiles)
{
	int	i;

	*nbytes = 0;
	*nfiles = 0;
	i = 1;
	while (i < argc)
	{
		if (is_c_flag(argv[i]))
		{
			i++;
			if (i >= argc)
				return (0);
			*nbytes = ft_atoi(argv[i]);
		}
		else if (is_c_attached(argv[i]))
			*nbytes = ft_atoi(argv[i] + 2);
		else
			(*nfiles)++;
		i++;
	}
	return (1);
}

int	get_mode(int nfiles, int idx)
{
	if (nfiles <= 1)
		return (0);
	if (idx == 0)
		return (1);
	return (2);
}

void	print_c_error(char *prog)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": option requires an argument -- 'c'\n", 37);
	write(2, "Try '", 5);
	write(2, prog, ft_strlen(prog));
	write(2, " --help' for more information.\n", 31);
}
