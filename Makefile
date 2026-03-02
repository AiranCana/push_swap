CFLAGS = -Wall -Werror -Wextra
NAME_BONUS = checker
NAME = push_swap

SOURCE = adaptive.c \
asign_stack.c \
basic_mov.c \
basic_mov_2stacks.c \
basic_rYrr.c \
basic_sYp.c \
complex.c \
disorder.c \
ft_atoi_long.c \
ft_flags_utils.c \
main.c \
mov_2stacks.c \
parser.c \
parse_int.c \
simple.c \
strverif.c \
utils.c 

BONUS_SOURCE = checker_bonus.c \
parser.c \
parse_int.c \
asign_stack.c \
ft_flags_utils.c \
get_next_line.c \
get_next_line_utils.c \
movements_bonus.c \
strverif.c \
basic_mov.c \
mov_2stacks_bonus.c \
ft_atoi_long.c \
basic_mov_2stacks.c \
basic_rYrr_bonus.c \
basic_sYp_bonus.c \
utils.c 

OBJ = $(SOURCE:.c=.o)
OBJ_BONUS = $(BONUS_SOURCE:.c=.o)

all: $(NAME) clean

bonus: $(NAME_BONUS) clean

lib:
	@make -C libft all clean
	@mv "libft/libft.a" .
	@echo "\033[0;32m ✓ Movida la libft precopilada\n\033[0m"

$(NAME): $(OBJ) lib
	@cc $(CFLAGS) $(OBJ) libft.a -o $(NAME)
	@echo "\033[0;32m ✓ Copilado el push_swap\n\033[0m"

$(NAME_BONUS): $(OBJ_BONUS) lib
	@cc $(CFLAGS) $(OBJ_BONUS) libft.a -o $(NAME_BONUS)
	@echo "\033[0;32m ✓ Copilado el checker\n\033[0m"

%.o: %.c
	@cc -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "\033[0;31m ✗ Eliminar los .o del push_swap y el checker\n\033[0m"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\033[0;31m ✗ Eliminar el copilado del push_swap y el checker\n\033[0m"

re: fclean all

