#include "rush02.h"

static unsigned long long	scale_at(int idx)
{
	unsigned long long	s;
	int					i;

	s = 1;
	i = 0;
	while (i < idx)
	{
		s = s * 1000;
		i++;
	}
	return (s);
}

static void	push(unsigned long long *keys, int *count, unsigned long long v)
{
	keys[*count] = v;
	(*count)++;
}

static void	decompose_group(unsigned long long g, unsigned long long *keys,
		int *count)
{
	unsigned long long	r;

	if (g >= 100)
	{
		push(keys, count, g / 100);
		push(keys, count, 100);
	}
	r = g % 100;
	if (r == 0)
		return ;
	if (r < 20)
	{
		push(keys, count, r);
		return ;
	}
	push(keys, count, (r / 10) * 10);
	if (r % 10 != 0)
		push(keys, count, r % 10);
}

static void	decompose(unsigned long long n, unsigned long long *keys,
		int *count)
{
	int					idx;
	unsigned long long	scale;
	unsigned long long	group;

	*count = 0;
	if (n == 0)
	{
		push(keys, count, 0);
		return ;
	}
	idx = 6;
	while (idx >= 0)
	{
		scale = scale_at(idx);
		group = (n / scale) % 1000;
		if (group != 0)
		{
			decompose_group(group, keys, count);
			if (idx > 0)
				push(keys, count, scale);
		}
		idx--;
	}
}

int	convert(t_entry *dict, unsigned long long n)
{
	unsigned long long	keys[256];
	int					count;

	decompose(n, keys, &count);
	if (!all_present(dict, keys, count))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	print_words(dict, keys, count);
	return (0);
}
