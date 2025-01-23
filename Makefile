PUSH_SWAP_NAME = push_swap
CHECKER_NAME = checker
LIBFT = libft.a
FT_PRINTF = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

PUSH_SWAP_DIR = ./push_swap
PUSH_SWAP_HEADER_DIR = $(PUSH_SWAP_DIR)/includes
PUSH_SWAP_SRCS_DIR = $(PUSH_SWAP_DIR)/srcs
PUSH_SWAP_OBJS_DIR = $(PUSH_SWAP_DIR)/objs

CHECKER_DIR = ./checker
CHECKER_HEADER_DIR = $(CHECKER_DIR)/includes
CHECKER_SRCS_DIR = $(CHECKER_DIR)/srcs
CHECKER_OBJS_DIR = $(CHECKER_DIR)/objs

LIBFT_DIR = ./libft
LIBFT_HEADER_DIR = $(LIBFT_DIR)/includes
LIBFT_SRCS_DIR = ./srcs

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_HEADER_DIR = $(FT_PRINTF_DIR)/includes
FT_PRINTF_SRCS_DIR = ./srcs

PUSH_SWAP_INCLUDES = -I$(PUSH_SWAP_HEADER_DIR) -I$(LIBFT_HEADER_DIR) -I$(FT_PRINTF_HEADER_DIR)
PUSH_SWAP_LIBRARIES = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

CHECKER_INCLUDES = -I$(CHECKER_HEADER_DIR) -I$(LIBFT_HEADER_DIR) -I$(FT_PRINTF_HEADER_DIR)
CHECKER_LIBRARIES = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

PUSH_SWAP_SRCS_FILES = \
		check_sorted.c \
		count_rotations.c \
		optimize_rotations.c \
		parse_params_utils.c \
		parse_params.c \
		push_swap.c \
		push.c \
		reverse_rotate_utils.c \
		reverse_rotate.c \
		rotate_utils.c \
		rotate.c \
		set_stack_utils.c \
		sort.c \
		stack_a_to_stack_b.c \
		stack_b_to_stack_a.c \
		stack_init_utils.c \
		stack_utils.c \
		swap_utils.c \
		swap.c

CHECKER_SRCS_FILES = \
		check_sorted.c \
		checker.c \
		parse_params_utils.c \
		parse_params.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		set_stack_a.c \
		stack_init_utils.c \
		swap.c \

PUSH_SWAP_OBJS = $(addprefix $(PUSH_SWAP_OBJS_DIR)/, $(PUSH_SWAP_SRCS_FILES:.c=.o))

CHECKER_OBJS = $(addprefix $(CHECKER_OBJS_DIR)/, $(CHECKER_SRCS_FILES:.c=.o))

all: $(LIBFT) $(FT_PRINTF) $(PUSH_SWAP_NAME)

bonus: $(LIBFT) $(FT_PRINTF) $(CHECKER_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_INCLUDES) $(CHECKER_OBJS) $(CHECKER_LIBRARIES) -o $(CHECKER_DIR)/$(CHECKER_NAME)

$(CHECKER_OBJS_DIR)/%.o: $(CHECKER_SRCS_DIR)/%.c
	@mkdir -p $(CHECKER_OBJS_DIR)
	$(CC) $(CFLAGS) $(CHECKER_INCLUDES) -c $< -o $@

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_INCLUDES) $(PUSH_SWAP_OBJS) $(PUSH_SWAP_LIBRARIES) -o $(PUSH_SWAP_DIR)/$(PUSH_SWAP_NAME)

$(PUSH_SWAP_OBJS_DIR)/%.o: $(PUSH_SWAP_SRCS_DIR)/%.c
	@mkdir -p $(PUSH_SWAP_OBJS_DIR)
	$(CC) $(CFLAGS) $(PUSH_SWAP_INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS)
	rm -f $(CHECKER_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(PUSH_SWAP_DIR)/$(PUSH_SWAP_NAME)
	rm -f $(CHECKER_DIR)/$(CHECKER_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
