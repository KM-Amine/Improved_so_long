/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:09:49 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 13:20:30 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "X.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h>
# define WINDOW_X 2560
# define WINDOW_Y 1440

//osascript -e 'tell application "Finder" to get bounds of window of desktop'
// display resolution

# define SPRITE_X 64
# define SPRITE_Y 64

// music librrary in /usr/local/include
// or system("afplay /Users/mkhellou/Downloads/lifelike-126735.mp3");

# define D 2
# define S 1
# define A 0
# define W 13
# define ESC 53

enum
{
	background,
	wall,
	collectibales,
	map_exit,
	player,
	go,
	patrol
};

enum
{
	right,
	up,
	down,
	left
};

enum
{
	DOWNRIGHT,
	DOWNLEFT,
	UPLEFT,
	UPRIGHT
};

enum
{
	press,
	release
};

typedef struct pos
{
	int			x;
	int			y;
}				pos;

typedef struct map_info
{
	char		**map;
	pos			resolution;
}				map_info;

typedef struct map_check
{
	int			rectangular;
	int			stranger_characters;
	int			minimum_characters;
	int			closed;
	int			no_exit;
	int			with_exit;
}				map_check;

typedef struct char_cont
{
	int			e;
	int			c;
	int			p;
}				char_cont;

typedef struct mlx_info
{
	void		*mlx;
	void		*mlx_win;
}				mlx_info;

typedef struct image_info
{
	void		*ptr[50];
	pos			resolution;
}				image_info;

typedef struct key
{
	int			status[2];
}				key;
typedef struct enemy
{
	int			direction;
	pos			p;
}				enemy;

typedef struct text_data
{
	int			mouvement;
	int			coins;
}				text_data;

typedef struct all_data
{
	map_info	map;
	mlx_info	mlx;
	image_info	*img;
	key			*keys;
	enemy		*enemy;
	text_data	text;
}				all_data;

typedef struct timing
{
	int	clock;
	int	framerate;
}				timing;

void			enemy_spawner(map_info *map);
void			enemy_respawner(map_info *map, enemy *enemy);
void			enemy_collector(all_data *data);

//utils for map
void			free_map(char **map);
char			**read_map(char *file);
char			**map_copy(char **map);
void			print_map(char **map);
void			get_dimentions(char **map, pos *cordonates);

void			get_cordonates(char **map, pos *cordonates, char c);

map_info		map_checker(int av, char **ac);
void			check_cordonates(char **map, pos *cordonates);
void			map_structure(map_check *check, char **map);
void			valid_path_handler(map_check *check, char **map);

int				key_release(int keycode, all_data *data);
int				key_press(int keycode, all_data *data);

void			images_generator(all_data *data);
void			images_destroyer(image_info *img, void *mlx);
void			simple_map_printer(void *mlx, void *mlx_win, void **image_set,
					all_data *data);

void			valid_path(map_check *check, char **map, int i);
void			path_no_exit(map_check *check, char **map);
void			map_error_handling(char **map);
char			**map_copy(char **map);
void			path_with_exit(map_check *check, char **map);
void			error_exit_function(map_check *check);
void			file_name_checker(char *str);

void			map_modifier(all_data *data, int clock);
int				elment_counter(char **map, char c);
void			enemy_spawner(map_info *map);
void			enemy_modifier(all_data *data, int clock, int frame_rate);

void			enemy_collector(all_data *data);
void			enemy_direction(char **map, all_data *data);

void			extreme_checker(all_data *data, char **map, enemy *en,
					int count);
void			up_direction(char **map, all_data *data, enemy *en, int count);
void			right_direction(char **map, all_data *data, enemy *en,
					int count);
void			down_direction(char **map, all_data *data, enemy *en,
					int count);
void			left_direction(char **map, all_data *data, enemy *en,
					int count);
int				key_press(int keycode, all_data *data);
void			image_modifier(image_info *img, void **image_set);
int				exit_free(void *param);

void			player_mouver(pos p, int x, int y, all_data *data);
void			player_modifier(all_data *data, int clock, int frame_rate);

#endif