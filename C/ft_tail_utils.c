#include "ft_tail.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	copy_bytes(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	print_open_error(char *prog, char *file)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": cannot open '", 15);
	write(2, file, ft_strlen(file));
	write(2, "' for reading: ", 15);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	print_read_error(char *prog, char *file)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": error reading '", 17);
	write(2, file, ft_strlen(file));
	write(2, "': ", 3);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int	get_mode(int nfiles, int idx)
{
	if (nfiles <= 1)
		return (0);
	if (idx == 0)
		return (1);
	return (2);
}
