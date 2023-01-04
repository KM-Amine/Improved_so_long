/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:10 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/04 18:37:22 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		key_press(int keycode, all_data *data);

void	image_modifier(image_info *img, void **image_set);

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

int	destroy(void *param)
{
	(void)param;
	exit(0);
}

int	main(int av, char **ac)
{
	map_info	map;
	mlx_info	mlx;
	image_info	*img;
	all_data	data;
	key			*keys;
	enemy		*enemi;

	keys = ft_calloc(5, sizeof(key));
	enemi = ft_calloc(20, sizeof(enemy));
	map = map_checker(av, ac);
	enemy_spawner(map.map);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, map.resolution.x * SPRITE_X,
			(map.resolution.y + 1) * SPRITE_Y, "so_long");
	img = (image_info *)ft_calloc(10, sizeof(image_info));
	images_generator(img, mlx.mlx);
	data.map = map;
	data.mlx = mlx;
	data.img = img;
	data.keys = keys;
	data.enemy = enemi;
	enemy_collector(&data);
	// player is on top of coin
	mlx_hook(mlx.mlx_win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(mlx.mlx_win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(mlx.mlx_win, DestroyNotify, NoEventMask, destroy, NULL);
	mlx_loop_hook(mlx.mlx, render_frame, &data);
	mlx_loop(mlx.mlx);
	free_map(map.map);
	images_destroyer(img, mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.mlx);
	free(data.mlx.mlx);
	return (0);
}
