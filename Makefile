SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c
OBJ = $(SRC:.c=.o)

all: libft.a

libft.a: $(OBJ)
	ar rcs libft.a $(OBJ)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

re: fclean all
