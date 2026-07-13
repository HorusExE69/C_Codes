#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	display_error(char *prog, char *file)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	ft_cat(int fd)
{
	char	buffer[28000];
	int		ret;

	ret = read(fd, buffer, 28000);
	while (ret > 0)
	{
		write(1, buffer, ret);
		ret = read(fd, buffer, 28000);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	if (argc == 1)
		ft_cat(0);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			display_error(basename(argv[0]), argv[i]);
		else
		{
			ft_cat(fd);
			close(fd);
		}
		i++;
	}
	return (0);
}
