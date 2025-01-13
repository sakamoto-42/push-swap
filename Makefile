NAME = push_swap
LIBFT = libft.a
FT_PRINTF = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

LIBFT_DIR = ./libft
LIBFT_HEADER_DIR = $(LIBFT_DIR)/includes
LIBFT_SRCS_DIR = ./srcs

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_HEADER_DIR = $(FT_PRINTF_DIR)/includes
FT_PRINTF_SRCS_DIR = ./srcs

INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER_DIR) -I$(FT_PRINTF_HEADER_DIR)
LIBRARIES = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

SRCS_FILES = \
		check_sorted.c \
		parse_params_utils.c \
		parse_params.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		set_stack_utils.c \
		sort.c \
		sort_utils.c \
		stack_init_utils.c \
		stack_utils.c \
		swap.c \

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBRARIES) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: allclean fclean re