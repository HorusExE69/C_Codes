#include "rush02.h"

int	run(char *path, char *numstr)
{
	unsigned long long	n;
	t_entry				*dict;
	int					err;
	int					status;

	if (!valid_number(numstr, &n))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	dict = load_dict(path, &err);
	if (err)
	{
		free_dict(dict);
		write(1, "Dict Error\n", 11);
		return (1);
	}
	status = convert(dict, n);
	free_dict(dict);
	return (status);
}

int	run_stdin(void)
{
	char	*input;
	int		status;

	input = read_all(0);
	if (!input)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	status = run("numbers.dict", input);
	free(input);
	return (status);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (run_stdin());
	if (argc == 2)
		return (run("numbers.dict", argv[1]));
	if (argc == 3)
		return (run(argv[1], argv[2]));
	write(1, "Error\n", 6);
	return (1);
}
