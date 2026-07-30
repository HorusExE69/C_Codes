#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

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

int	cat_fd(int fd, char *prog, char *name)
{
	char	buffer[28000];
	int		ret;

	ret = read(fd, buffer, 28000);
	while (ret > 0)
	{
		write(1, buffer, ret);
		ret = read(fd, buffer, 28000);
	}
	if (ret < 0)
	{
		display_error(prog, name);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	err;

	i = 1;
	err = 0;
	if (argc == 1)
		return (cat_fd(0, argv[0], "standard input"));
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			display_error(argv[0], argv[i]);
			err = 1;
		}
		else
		{
			err += cat_fd(fd, argv[0], argv[i]);
			close(fd);
		}
		i++;
	}
	return (err != 0);
}
