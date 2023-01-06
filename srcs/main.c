/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:10 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/05 19:48:42 by mkhellou         ###   ########.fr       */
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
		simple_map_printer(data->mlx.mlx, data->mlx.mlx_win, image_set,
				data->map);
	}
	i++;
	return (0);
}

int exit_free(void *param)
{
	(void)param;
	ft_printf("-----exit done----\n");
	exit(0);
}

int	main(int av, char **ac)
{
	all_data	data;

	data.keys = ft_calloc(5, sizeof(key));
	data.enemy  = ft_calloc(20, sizeof(enemy));
	data.map = map_checker(av, ac);

// enemy
	enemy_spawner(data.map.map);
	enemy_collector(&data);

// window initialisation
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, data.map.resolution.x * SPRITE_X,
			(data.map.resolution.y + 1) * SPRITE_Y, "so_long");

// image creation
	data.img = (image_info *)ft_calloc(10, sizeof(image_info));
	images_generator(data.img, data.mlx.mlx);
		
	// player is on top of coin
	

// hooking
	mlx_hook(data.mlx.mlx_win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.mlx.mlx_win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.mlx.mlx_win, DestroyNotify, NoEventMask, exit_free, NULL);

//main system
	mlx_loop_hook(data.mlx.mlx, render_frame, &data);
	mlx_loop(data.mlx.mlx);

// exiting
	free_map(data.map.map);
	images_destroyer(data.img, data.mlx.mlx);
	mlx_destroy_window(data.mlx.mlx, data.mlx.mlx);
	free(data.mlx.mlx);
	return (0);
}
