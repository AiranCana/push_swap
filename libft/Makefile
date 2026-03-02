CFLAGS = -Wall -Werror -Wextra -fPIC
NAME = libft.a

SOURCE=ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[0;32m ✓ Libft precopilada\n\033[0m"

%.o: %.c
	@cc -c $(CFLAGS) $< -o $@ 

clean:
	@rm -rf $(OBJ)
	@echo "\033[0;31m ✗ Eliminar los .o de la libft\n\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m ✗ Eliminar el precopilado de la libft\n\033[0m"

re: fclean all

bonus: all

.PHONY: bonus re fclean all clean