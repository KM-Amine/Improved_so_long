/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-image_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:30:42 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 13:20:24 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	simple_map_printer(void **image_set, all_data *data)
{
	char	*set;

	set = "01ECPGT";
	score_layer(image_set, data);
	backgroud_layer(set, image_set, data);
	player_layer(set, image_set, data);
}

void	player_layer(char *set, void **image_set, all_data *data)
{
	char	**copy;
	int		i;
	int		j;
	int		index;

	copy = map_copy(data->map.map);
//	if (!copy)
		////total_clean(data);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (ft_strchr("CPT", copy[i][j]))
			{
				index = ft_strchr(set, copy[i][j]) - set;
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					image_set[index], SPRITE_X * j, SPRITE_Y * i);
			}
			j++;
		}
		i++;
	}
	//free_map(copy);
}
