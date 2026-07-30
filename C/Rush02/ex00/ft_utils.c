#include "rush02.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	skip_spaces(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

int	skip_ws(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r')
		i++;
	return (i);
}

int	trim_end(char *s, int start, int end)
{
	while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t'))
		end--;
	return (end);
}

int	next_line(char *s, int i)
{
	if (s[i] == '\n')
		return (i + 1);
	return (i);
}
