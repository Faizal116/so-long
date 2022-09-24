NAME = so_long
SRC = *.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
INC = -lmlx -Llibft

all : $(NAME)

$(NAME): $(OBJ) libft
		$(CC) -o $(OBJ) $(INC) $(FRAMEWORK)

%.o: %.c
		$(CC) -c $(FLAGS) $?

libft:
		make -C libft

clean:
		rm -f $(OBJ)
		make -C libft clean

fclean: clean
		rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re