NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = append_node.c init.c main.c stack_ops.c \
		stack_ops_2.c stack_ops_3.c utils.c \
		radix_sorts.c radix_sorts_min.c radix_sorts_mi.c 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re