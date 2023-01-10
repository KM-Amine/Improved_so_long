NAME = so_long
BNAME = so_long_bonus
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

SRC = srcs/1-main.c \
	srcs/2-enemy_direction.c \
	srcs/2-enemy_manager.c \
	srcs/2-enemy_movement.c \
	srcs/2-key_manager.c \
	srcs/2-player_manager.c \
	srcs/3-map_updater.c \
	srcs/4-image_animator.c \
	srcs/4-image_generator.c \
	srcs/5-image_render_background.c \
	srcs/5-image_render_score.c \
	srcs/5-image_renderer.c \
	srcs/map_check_analyser.c \
	srcs/map_check_error.c \
	srcs/map_check_handler.c \
	srcs/map_check_path.c \
	srcs/map_utils.c

OBJ = $(SRC:srcs/%.c=objs/%.o)

BSRC = bsrcs/1-main.c \
		bsrcs/2-enemy_direction.c \
		bsrcs/2-enemy_manager.c \
		bsrcs/2-enemy_movement.c \
		bsrcs/2-key_manager.c \
		bsrcs/2-player_manager.c \
		bsrcs/3-map_updater.c \
		bsrcs/4-image_animator.c \
		bsrcs/4-image_generator.c \
		bsrcs/5-image_render_background.c \
		bsrcs/5-image_render_score.c \
		bsrcs/5-image_renderer.c \
		bsrcs/map_check_analyser.c \
		bsrcs/map_check_error.c \
		bsrcs/map_check_handler.c \
		bsrcs/map_check_path.c \
		bsrcs/map_utils.c \

BOBJ = $(BSRC:bsrcs/%.c=bobjs/%.o)

OBJDIR = objs
BOBJDIR = bobjs

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

objs/%.o: srcs/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(LIBFT) : $(LOBJ)
	@$(MAKE) -C libft
libft/%.o: libft/%.c
	@$(CC) $(LFLAGS) -c $< -o $@


bonus : $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

bobjs/%.o: bsrcs/%.c $(HEADER)
	@mkdir -p $(BOBJDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(BOBJDIR)
	@$(MAKE) fclean -C libft
fclean: clean
	@$(RM) $(NAME) $(BNAME)
	@echo "\033[1;32m ----Project cleaned----- \033[0m"

re: fclean all
bre: fclean bonus

.PHONY: all clean fclean re bonus
