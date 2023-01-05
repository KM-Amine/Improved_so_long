/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/05 15:37:34 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_exit(char **map)
{
	pos	p;

	get_cordonates(map, &p, 'E');
	if (p.x == -1)
		return ;
	map[p.x][p.y] = 'G';
}

void	finish_game(all_data *data)
{
	char	**map;

	map = data->map.map;
	if (elment_counter(map, 'C') == 0)
	{
		set_exit(map);
		if (elment_counter(map, 'G') == 0)
		{
			ft_printf("You won");
			exit(0);
		}
	}
}

void	player_mouver(char **map, pos p, int x, int y)
{
	static int	i;

	if (map[p.y + y][p.x + x] != '1' && map[p.y + y][p.x + x] != 'E')
	{
		i++;
		ft_printf("Player mouved : %d times\n", i);
		map[p.y][p.x] = '0';
		map[p.y + y][p.x + x] = 'P';
	}
}

int	key_press(int keycode, all_data *data)
{
	pos	p;

	get_cordonates(data->map.map, &p, 'P');
	if (keycode == D)
	{
		data->keys[right].status[0] = 1;
		data->keys[right].status[1] = 0;
	}
	if (keycode == W)
	{
		data->keys[up].status[0] = 1;
		data->keys[up].status[1] = 0;
	}
	if (keycode == S)
	{
		data->keys[down].status[0] = 1;
		data->keys[down].status[1] = 0;
	}
	if (keycode == A)
	{
		data->keys[left].status[0] = 1;
		data->keys[left].status[1] = 0;
	}
	if (keycode == ESC)
	{
		data->keys[4].status[0] = 1;
		exit_free(NULL);
	}
	return (0);
}

int	key_release(int keycode, all_data *data)
{
	pos	p;

	get_cordonates(data->map.map, &p, 'P');
	if (keycode == D)
	{
		data->keys[right].status[0] = 0;
		data->keys[right].status[1] = 1;
	}
	if (keycode == W)
	{
		data->keys[up].status[0] = 0;
		data->keys[up].status[1] = 1;
	}
	if (keycode == S)
	{
		data->keys[down].status[0] = 0;
		data->keys[down].status[1] = 1;
	}
	if (keycode == A)
	{
		data->keys[left].status[0] = 0;
		data->keys[left].status[1] = 1;
	}
	if (keycode == ESC)
	{
		data->keys[4].status[0] = 1;
	}
	ft_printf("%d %d\n", data->keys[0].status[0], data->keys[0].status[1]);
	return (0);
}

void	player_modifier(all_data *data, int clock, int frame_rate)
{
	pos	p;

	if (clock % frame_rate == 0)
	{
		get_cordonates(data->map.map, &p, 'P');
		if (data->keys[right].status[press] == 1)
			player_mouver(data->map.map, p, 1, 0);
		else if (data->keys[up].status[press] == 1)
			player_mouver(data->map.map, p, 0, -1);
		else if (data->keys[down].status[press] == 1)
			player_mouver(data->map.map, p, 0, 1);
		else if (data->keys[left].status[press] == 1)
			player_mouver(data->map.map, p, -1, 0);
	}
}

void	map_modifier(all_data *data, int clock)
{
	enemy_direction(data->map.map, data);
	enemy_modifier(data, clock, 1);
	player_modifier(data, clock, 2);
	finish_game(data);
}
