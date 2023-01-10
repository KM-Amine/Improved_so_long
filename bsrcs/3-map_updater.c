/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-map_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:49:51 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_modifier(t_all_data *data, int clock)
{
	enemy_modifier(data, clock, 50);
	player_modifier(data, clock, 5);
	finish_game(data, 0);
}

void	images_destroyer(t_all_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 10)
		{
			if (data->img[j].ptr[i] == NULL)
				break ;
			mlx_destroy_image(data->mlx.mlx, data->img[j].ptr[i]);
			j++;
		}
		i++;
	}
}

void	total_clean(t_all_data *data)
{
	free_map(data->map.map);
	images_destroyer(data);
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	free(data->mlx.mlx);
	exit(0);
}
