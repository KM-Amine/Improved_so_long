/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 15:16:50 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_layer(char *set, void **image_set, map_info map, void *mlx, void *mlx_win)
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
				mlx_put_image_to_window(mlx, mlx_win, image_set[index], SPRITE_X* j, SPRITE_Y * i);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
}

void	simple_map_printer(void *mlx, void *mlx_win, void **image_set,
		all_data *data)
{
	char	*set;

	set = "01ECPGT";
	score_layer(image_set, data);
	backgroud_layer(image_set, data);
	player_layer(set, image_set, data->map, mlx, mlx_win);
}
