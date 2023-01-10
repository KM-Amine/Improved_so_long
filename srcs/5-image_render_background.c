// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   5-image_render_background.c                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/08 14:20:59 by mkhellou          #+#    #+#             */
// /*   Updated: 2023/01/10 13:20:08 by mkhellou         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/so_long.h"

// void	set_map_data(char **map, char c, char *set)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (ft_strchr(set, map[i][j]))
// 				map[i][j] = c;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	zero_printer(all_data *data, void **image_set)
// {
// 	char	**copy;
// 	int		i;
// 	int		j;

// 	copy = map_copy(data->map.map);
// 	//if (!copy)
// 		//total_clean(data);
// 	set_map_data(copy, '0', "CP1EGT");
// 	i = 0;
// 	while (copy[i])
// 	{
// 		j = 0;
// 		while (copy[i][j])
// 		{
// 			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
// 				image_set[background], SPRITE_X * j, SPRITE_Y * i);
// 			j++;
// 		}
// 		i++;
// 	}
// 	//free_map(copy);
// }

// void	wall_exit_printer(char *set, all_data *data, void **image_set)
// {
// 	int		i;
// 	int		j;
// 	char	**copy;
// 	int		index;

// 	copy = map_copy(data->map.map);
// 	//if (!copy)
// 		//total_clean(data);
// 	i = 0;
// 	while (copy[i])
// 	{
// 		j = 0;
// 		while (copy[i][j])
// 		{
// 			if (ft_strchr("1EG", copy[i][j]))
// 			{
// 				index = ft_strchr(set, copy[i][j]) - set;
// 				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
// 					image_set[index], SPRITE_X * j, SPRITE_Y * i);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	//free_map(copy);
// }


// void	backgroud_layer(char *set, void **image_set, all_data *data)
// {
// 	zero_printer(data, image_set);
// 	wall_exit_printer(set, data, image_set);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-image_render_background.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:20:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 18:48:37 by mkhellou         ###   ########.fr       */
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

////--------------------
void	zero_printer(all_data *data, void **image_set)
{
	char	**copy;
	int		i;
	int		j;

	copy = map_copy(data->map.map);
	set_map_data(copy, '0', "CP1EGT");
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				image_set[background], SPRITE_X * j, SPRITE_Y * i);
			j++;
		}
		i++;
	}
	free_map(copy);
}
////--------------------
void	wall_exit_printer(char *set, all_data *data, void **image_set)
{
	int		i;
	int		j;
	char	**copy;
	int		index;

	copy = map_copy(data->map.map);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (ft_strchr("1EG", copy[i][j]))
			{
				index = ft_strchr(set, copy[i][j]) - set;
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					image_set[index], SPRITE_X * j, SPRITE_Y * i);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
}
////--------------------

void	backgroud_layer(char *set, void **image_set, all_data *data)
{
	zero_printer(data, image_set);
	wall_exit_printer(set, data, image_set);
}