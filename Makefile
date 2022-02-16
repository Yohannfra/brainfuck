CC = gcc

NAME = brainfuck

SRC = main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
