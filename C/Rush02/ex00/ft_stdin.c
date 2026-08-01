#include "rush02.h"

int	empty_line(char *s)
{
	int	i;

	i = skip_ws(s, 0);
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	process_lines(t_entry *dict, char *s)
{
	int		i;
	int		start;
	int		status;
	char	*line;

	status = 0;
	i = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != '\n')
			i++;
		line = substr(s, start, i);
		if (line && !empty_line(line))
			status += convert_str(dict, line);
		free(line);
		if (s[i] == '\n')
			i++;
	}
	return (status != 0);
}

int	convert_stdin(t_entry *dict)
{
	char	*input;
	int		status;

	input = read_all(0);
	if (!input)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	status = process_lines(dict, input);
	free(input);
	return (status);
}
