NAME = so_long_bonus
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I ./includes 
RM = rm -rf
HEADER  = includes/so_long.h

LIBFT = libft/libft.a 
LSRC = ft_atoi.c \
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
	ft_printf.c \
	ft_printf_utils.c \
	get_next_line.c \
LOBJ =$(LSRC:%.c=libft/%.o)

SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:srcs/%.c=objs/%.o)


all: $(LIBFT) $(NAME)
	./git.sh
	./$(NAME) map.ber
#	^
#	|
######change this shit!!!!!!!!######



norm:
	bash ~/nor.sh ./**/*.c ./**/*.h
#	^
#	|
######change this shit!!!!!!!!######

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

objs/%.o: srcs/%.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT) : $(LOBJ)
	$(MAKE) -C libft
libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C libft
fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus