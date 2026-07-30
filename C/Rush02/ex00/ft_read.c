#include "rush02.h"

char	*append(char *data, int size, char *buf, int n)
{
	char	*tmp;
	int		i;

	tmp = malloc(size + n + 1);
	if (!tmp)
	{
		free(data);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		tmp[i] = data[i];
		i++;
	}
	while (i < size + n)
	{
		tmp[i] = buf[i - size];
		i++;
	}
	tmp[i] = '\0';
	free(data);
	return (tmp);
}

char	*read_all(int fd)
{
	char	buf[4096];
	char	*data;
	int		size;
	int		ret;

	data = malloc(1);
	if (!data)
		return (NULL);
	data[0] = '\0';
	size = 0;
	ret = read(fd, buf, 4096);
	while (ret > 0)
	{
		data = append(data, size, buf, ret);
		if (!data)
			return (NULL);
		size += ret;
		ret = read(fd, buf, 4096);
	}
	if (ret < 0)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

char	*substr(char *s, int start, int end)
{
	char	*out;
	int		i;

	out = malloc(end - start + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (start < end)
	{
		out[i] = s[start];
		i++;
		start++;
	}
	out[i] = '\0';
	return (out);
}

int	fail(int *err)
{
	*err = 1;
	return (0);
}

int	valid_number(char *s, unsigned long long *n)
{
	int	i;
	int	digits;

	i = skip_ws(s, 0);
	if (s[i] == '+')
		i++;
	*n = 0;
	digits = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (*n > 1844674407370955161ULL)
			return (0);
		if (*n == 1844674407370955161ULL && (s[i] - '0') > 5)
			return (0);
		*n = *n * 10 + (s[i] - '0');
		digits = 1;
		i++;
	}
	i = skip_ws(s, i);
	if (!digits || s[i] != '\0')
		return (0);
	return (1);
}
