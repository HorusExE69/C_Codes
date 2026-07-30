NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_utils.c ft_read.c ft_dict.c ft_words.c ft_convert.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
