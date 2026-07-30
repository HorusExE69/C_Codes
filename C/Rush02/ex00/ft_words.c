#include "rush02.h"

void	free_dict(t_entry *head)
{
	t_entry	*next;

	while (head)
	{
		next = head->next;
		free(head->value);
		free(head);
		head = next;
	}
}

char	*lookup(t_entry *dict, unsigned long long key)
{
	while (dict)
	{
		if (dict->key == key)
			return (dict->value);
		dict = dict->next;
	}
	return (NULL);
}

int	all_present(t_entry *dict, unsigned long long *keys, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!lookup(dict, keys[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_words(t_entry *dict, unsigned long long *keys, int n)
{
	int		i;
	char	*val;

	i = 0;
	while (i < n)
	{
		val = lookup(dict, keys[i]);
		if (i > 0)
			write(1, " ", 1);
		write(1, val, ft_strlen(val));
		i++;
	}
	write(1, "\n", 1);
}
