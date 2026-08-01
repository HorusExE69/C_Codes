#include "rush02.h"

static void	push(unsigned long long *keys, int *count, unsigned long long v)
{
	keys[*count] = v;
	(*count)++;
}

static int	is_mult(unsigned long long k)
{
	if (k == 100)
		return (1);
	if (k < 1000)
		return (0);
	while (k % 1000 == 0)
		k = k / 1000;
	return (k == 1);
}

static unsigned long long	largest_key(t_entry *dict, unsigned long long n)
{
	unsigned long long	best;

	best = 0;
	while (dict)
	{
		if (dict->key <= n && dict->key > best)
			best = dict->key;
		dict = dict->next;
	}
	return (best);
}

int	decompose(t_entry *dict, unsigned long long n, unsigned long long *keys,
		int *count)
{
	unsigned long long	big;

	if (*count >= 500)
		return (1);
	if (n == 0)
	{
		push(keys, count, 0);
		return (0);
	}
	big = largest_key(dict, n);
	if (big == 0 || (big == 1 && n > 1))
		return (1);
	if (is_mult(big) || n / big > 1)
	{
		if (decompose(dict, n / big, keys, count))
			return (1);
	}
	push(keys, count, big);
	if (n % big != 0)
		return (decompose(dict, n % big, keys, count));
	return (0);
}
