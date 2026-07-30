#include "rush02.h"

int	parse_key(char *s, int i, unsigned long long *key)
{
	int	start;

	if (s[i] == '+' || s[i] == '-')
		i++;
	start = i;
	*key = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		*key = *key * 10 + (s[i] - '0');
		i++;
	}
	if (i == start)
		return (-1);
	return (i);
}

int	add_entry(t_entry **head, unsigned long long key, char *val)
{
	t_entry	*e;

	e = malloc(sizeof(t_entry));
	if (!e)
	{
		free(val);
		return (0);
	}
	e->key = key;
	e->value = val;
	e->next = *head;
	*head = e;
	return (1);
}

int	parse_line(char *s, int i, t_entry **head, int *err)
{
	unsigned long long	key;
	int					vs;
	int					ve;
	char				*val;

	i = skip_spaces(s, i);
	if (s[i] == '\0' || s[i] == '\n')
		return (next_line(s, i));
	i = parse_key(s, i, &key);
	if (i < 0)
		return (fail(err));
	i = skip_spaces(s, i);
	if (s[i] != ':')
		return (fail(err));
	i = skip_spaces(s, i + 1);
	vs = i;
	while (s[i] && s[i] != '\n')
		i++;
	ve = trim_end(s, vs, i);
	val = substr(s, vs, ve);
	if (!val || !add_entry(head, key, val))
		*err = 1;
	return (next_line(s, i));
}

t_entry	*parse_dict(char *s, int *err)
{
	t_entry	*head;
	int		i;

	head = NULL;
	*err = 0;
	i = 0;
	while (s[i])
	{
		i = parse_line(s, i, &head, err);
		if (*err)
			return (head);
	}
	return (head);
}

t_entry	*load_dict(char *path, int *err)
{
	int		fd;
	char	*content;
	t_entry	*dict;

	*err = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*err = 1;
		return (NULL);
	}
	content = read_all(fd);
	close(fd);
	if (!content)
	{
		*err = 1;
		return (NULL);
	}
	dict = parse_dict(content, err);
	free(content);
	return (dict);
}
