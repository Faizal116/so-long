NAME = so_long
SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}
LIB = -L./libft -lft -lmlx
INC = -Iincludes -Imlx -Ilibft

CC = gcc
FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
FRAMEWORK = -framework OpenGL -framework AppKit

all : ${NAME}

${NAME}: $(OBJ)
		@make -C libft
		@${CC} ${FLAGS} ${LIB} ${INC} $(addprefix obj/, ${OBJ}) ${FRAMEWORK} -o $@

%.o: %.c
		@mkdir -p obj
		@${CC} ${FLAGS} ${INC} -c $< -o obj/$@

clean:
		@rm -rf obj

fclean: clean
		@rm -rf ${NAME}
		@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re