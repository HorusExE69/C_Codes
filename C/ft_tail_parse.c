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

int	parse_number(char *s, long *out)
{
	unsigned long long	n;
	int					i;
	int					over;

	n = 0;
	over = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (2);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (2);
		if (n > 922337203685477580ULL)
			over = 1;
		n = n * 10 + (s[i] - '0');
		if (n > 9223372036854775807ULL)
			over = 1;
		i++;
	}
	if (over)
		return (3);
	*out = (long)n;
	return (0);
}

void	init_opts(t_opts *o)
{
	o->nbytes = 0;
	o->nfiles = 0;
	o->err = 0;
	o->bad = NULL;
}

void	handle_value(t_opts *o, char *arg)
{
	int	r;

	r = parse_number(arg, &o->nbytes);
	if (r != 0)
	{
		o->err = r;
		o->bad = arg;
	}
}
