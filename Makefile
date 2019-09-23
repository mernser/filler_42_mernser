NAME = mernser.filler

FLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

SAN =  $(FLAGS) -fsanitize=address

G = -g

HEADER = $(wildcard *.h)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc -g -o $(NAME) $(OBJ) -I. -L ./libft -lft

g:
	gcc $(G) -o $(NAME) $(OBJ) -L ./libft -lft

san:
	gcc $(G) $(SAN) -o $(NAME) $(OBJ) -L ./libft -lft

fun:
	 cat *.c | grep "ft_*"

%.o: %.c $(HEADER)
	gcc -g $(FLAGS) -c $< -o $@

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
