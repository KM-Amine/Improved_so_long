/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/07 13:23:02 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_map_data(char **map, char c, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(set, map[i][j]))
				map[i][j] = c;
			j++;
		}
		i++;
	}
}

char *score_creator(int i,char c)
{
	char *tmp;
	char *str;

	tmp = ft_itoa(i);
	if (c == 'M')
		str = ft_strjoin("Number of movements: ",tmp);
	else
		str = ft_strjoin("Number of coins left: ",tmp);
	free(tmp);
	return (str);
}

void score_layer(char *set, void **image_set, all_data *data, void *mlx,void *mlx_win)
{
	int j;
	int i;
	int mouvement;
	char *mvstr;
	(void)set;
	j = data->map.resolution.y;
	i = 0;
	mouvement=data->text.mouvement;
	mlx_clear_window(mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, image_set[7], i* SPRITE_X, j * SPRITE_Y);
	while(i < data->map.resolution.x)
	{
		mlx_put_image_to_window(mlx, mlx_win, image_set[8], i* SPRITE_X, j * SPRITE_Y);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, image_set[9], (i-1)* SPRITE_X, j * SPRITE_Y);
	mvstr = score_creator(mouvement,'M');
	mlx_string_put(mlx, mlx_win,SPRITE_X/2,(j * SPRITE_Y)+ SPRITE_Y/3,0x0000FFFF,mvstr);
	mvstr = score_creator(mouvement,'C');
	mlx_string_put(mlx, mlx_win,i*SPRITE_X/2,(j * SPRITE_Y)+ SPRITE_Y/3,0x0000FFFF,mvstr);
	free(mvstr);
}

void	backgroud_layer(char *set, void **image_set, map_info map, void *mlx,
		void *mlx_win)
{
	char	**copy;
	int		i;
	int		j;
	int		index;

	copy = map_copy(map.map);
	set_map_data(copy, '0', "CP1EGT");
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			index = ft_strchr(set, copy[i][j]) - set;
			mlx_put_image_to_window(mlx, mlx_win, image_set[index], SPRITE_X
					* j, SPRITE_Y * i);
			j++;
		}
		i++;
	}
	free_map(copy);
	copy = map_copy(map.map);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (ft_strchr("1EG", copy[i][j]))
			{
				index = ft_strchr(set, copy[i][j]) - set;
				mlx_put_image_to_window(mlx, mlx_win, image_set[index], SPRITE_X
						* j, SPRITE_Y * i);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
}
void	player_layer(char *set, void **image_set, map_info map, void *mlx,
		void *mlx_win)
{
	char	**copy;
	int		i;
	int		j;
	int		index;

	(void)set;
	copy = map_copy(map.map);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (ft_strchr("CPT", copy[i][j]))
			{
				if (copy[i][j] == 'C')
					index = 3;
				else if (copy[i][j] == 'P')
					index = 4;
				else if (copy[i][j] == 'T')
					index = 6;
				mlx_put_image_to_window(mlx, mlx_win, image_set[index], SPRITE_X
						* j, SPRITE_Y * i);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
}


void	simple_map_printer(void *mlx, void *mlx_win, void **image_set,all_data *data)
{
	char *set = "01ECPGT";

	score_layer(set, image_set, data, mlx, mlx_win);
	backgroud_layer(set, image_set, data->map, mlx, mlx_win);
	player_layer(set, image_set, data->map, mlx, mlx_win);
}