/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:10 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 13:10:48 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_frame(all_data *data)
{
	static int	i;
	static void	*image_set[50];

	if (i % 1 == 0)
	{
		map_modifier(data, i);
		image_modifier(data->img, image_set);
		simple_map_printer(image_set, data);
	}
	i++;
	return (0);
}

int	exit_cross(all_data *data)
{
	finish_game(data, 4);
	return (0);
}

// static functions
// malloc free
// if malloc returns NULL



//initialize data with 0
void	data_intialisation(all_data *data, key *keys, enemy *enemies,
		image_info *img)
{
	data->keys = keys;
	ft_bzero(keys, sizeof(key) * 5);
	data->text = (text_data){0, 0};
	ft_bzero(enemies, sizeof(enemy) * 20);
	data->enemy = enemies;
	ft_bzero(img, sizeof(image_info) * 10);
	data->img = img;
	data->exit_status=0;
}

int	main(int av, char **ac)
{
	all_data	data;
	key			keys[5];
	enemy		enemies[20];
	image_info	img[10];

	data.map = map_checker(av, ac);
	data_intialisation(&data, keys, enemies, img);
	enemy_spawner(&data.map);
	enemy_collector(&data);
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, data.map.resolution.x
			* SPRITE_X, (data.map.resolution.y + 1) * SPRITE_Y, "so_long");
	images_generator(&data);
	mlx_hook(data.mlx.mlx_win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.mlx.mlx_win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.mlx.mlx_win, DestroyNotify, NoEventMask, exit_cross, &data);
	mlx_loop_hook(data.mlx.mlx, render_frame, &data);
	mlx_loop(data.mlx.mlx);
	total_clean(&data);
	return (0);
}

	// player is on top of coin
	// return value of mlx functions
	