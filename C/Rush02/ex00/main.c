#include "rush02.h"

int	convert_str(t_entry *dict, char *numstr)
{
	unsigned long long	n;

	if (!valid_number(numstr, &n))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (convert(dict, n));
}

int	run(char *path, char *numstr)
{
	t_entry	*dict;
	int		err;
	int		status;

	dict = load_dict(path, &err);
	if (err)
	{
		free_dict(dict);
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (numstr[0] == '-' && numstr[1] == '\0')
		status = convert_stdin(dict);
	else
		status = convert_str(dict, numstr);
	free_dict(dict);
	return (status);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (run("numbers.dict", argv[1]));
	if (argc == 3)
		return (run(argv[1], argv[2]));
	write(1, "Error\n", 6);
	return (1);
}
