NAME = push_swap
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER_DIR)

LIBFT_DIR = ./libft
LIBFT_HEADER_DIR = $(LIBFT_DIR)/includes
LIBFT_SRCS_DIR = ./srcs

HEADER_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS_FILES = \
		check_sorted.c \
		parse_params_utils.c \
		parse_params.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		set_stack_utils.c \
		sort_stack_a.c \
		sort_utils.c \
		stack_init_utils.c \
		stack_utils.c \
		swap.c \

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: allclean fclean re