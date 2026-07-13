#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	read_and_display(int fd)
{
	char	buffer[4096];
	int		ret;

	ret = read(fd, buffer, 4096);
	while (ret > 0)
	{
		write(1, buffer, ret);
		ret = read(fd, buffer, 4096);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr_error("File name missing.");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr_error("Too many arguments.");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_error("Cannot read file.");
		return (0);
	}
	read_and_display(fd);
	close(fd);
	return (0);
}
