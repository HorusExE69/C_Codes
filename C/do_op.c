#include "do_op.h"

void	fill_ops(int (*ops[5])(int, int))
{
	ops[0] = op_add;
	ops[1] = op_sub;
	ops[2] = op_mul;
	ops[3] = op_div;
	ops[4] = op_mod;
}

int	get_op_index(char *op)
{
	char	*symbols;
	int		i;

	if (!op[0] || op[1])
		return (-1);
	symbols = "+-*/%";
	i = 0;
	while (symbols[i])
	{
		if (symbols[i] == op[0])
			return (i);
		i++;
	}
	return (-1);
}

void	print_zero_error(char op)
{
	if (op == '/')
		write(1, "Stop : division by zero\n", 24);
	else
		write(1, "Stop : modulo by zero\n", 22);
}

int	main(int argc, char **argv)
{
	int	(*ops[5])(int, int);
	int	i;
	int	v1;
	int	v2;

	if (argc != 4)
		return (0);
	fill_ops(ops);
	i = get_op_index(argv[2]);
	if (i < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	v1 = ft_atoi(argv[1]);
	v2 = ft_atoi(argv[3]);
	if ((i == 3 || i == 4) && v2 == 0)
	{
		print_zero_error(argv[2][0]);
		return (0);
	}
	put_nbr(ops[i](v1, v2));
	write(1, "\n", 1);
	return (0);
}
