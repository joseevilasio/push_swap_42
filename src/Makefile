NAME := push_swap

NAME_BONUS := push_swap_bonus

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libs/libft/libft.a

LIBFT_DIR := libs/libft

SRCS := src/op.c\
	src/push_swap.c\
	src/utils.c\
	src/free_error_handler.c\

# SRCS_BONUS := 

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT)	$(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME_BONUS) 

clean:
	make clean -C $(LIBFT_DIR)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all bonus clean fclean re