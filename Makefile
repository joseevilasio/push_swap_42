NAME := push_swap

NAME_BONUS := checker

CC := cc

AR := ar rcs

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libs/libft/libft.a

LIBFT_DIR := libs/libft

SRCS := src/push_swap.c\
	src/free_error_handler.c\
	src/deep_sort.c\
	src/stack_utils.c\
	src/stack_update.c\
	src/stack_manipulation.c\
	src/stack_factory.c\
	src/parser.c\
	src/main.c\

SRCS_BONUS := bonus/checker_bonus.c\
	bonus/free_error_handler_bonus.c\
	bonus/parser_bonus.c\
	bonus/push_swap_bonus.c\
	bonus/stack_factory_bonus.c\
	bonus/stack_manipulation_bonus.c\

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME) $(NAME_BONUS)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

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