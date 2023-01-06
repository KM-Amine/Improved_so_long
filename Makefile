NAME = so_long_bonus
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I ./includes 
RM = rm -rf
HEADER  = includes/so_long.h


LFLAGS = -Wall -Wextra -Werror
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
	get_next_line_utils.c
LOBJ = $(LSRC:%.c=libft/%.o)

SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:srcs/%.c=objs/%.o)
OBJDIR = objs

all:  $(NAME)
	./$(NAME) map.ber
#	^
#	|
######	Delete this shit!!!!!!!!######
fgit :
	./git.sh
#	^
#	|
######	Delete this shit!!!!!!!!######
norm:
	bash ~/nor.sh ./**/*.c ./**/*.h
#^
#|
######	Delete this shit!!!!!!!!######



$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

objs/%.o: srcs/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT) : $(LOBJ)
	@$(MAKE) -C libft
libft/%.o: libft/%.c
	@$(CC) $(LFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@$(MAKE) fclean -C libft
fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(NAME)
	@echo "\033[1;32m ----Project cleaned----- \033[0m"
re: fclean all

.PHONY: all clean fclean re bonus
