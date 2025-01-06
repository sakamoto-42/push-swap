NAME = push_swap
LIBFT = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_DIR)/$(LIBFT_HEADER_DIR)

LIBFT_DIR = ./libft
LIBFT_HEADER_DIR = includes
LIBFT_SRCS_DIR = ./srcs

HEADER_DIR = ./includes
SRCS_DIR = ./srcs
OBJ_DIR = ./objs

SRCS_FILES = \
		push_swap.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: allclean fclean re