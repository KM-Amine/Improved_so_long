/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-map_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 19:44:18 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_mouver(pos p, int x, int y, all_data *data)
{
	static int	i;

	if (data->map.map[p.y + y][p.x + x] == 'T')
		finish_game(data, 3);
	if (data->map.map[p.y + y][p.x + x] != '1' && data->map.map[p.y + y][p.x
		+ x] != 'E')
	{
		i++;
		data->text.mouvement = i;
		data->text.coins = elment_counter(data->map.map, 'C');
		ft_printf("Player mouved : %d times\n", i);
		data->map.map[p.y][p.x] = '0';
		data->map.map[p.y + y][p.x + x] = 'P';
	}
}

void	player_modifier(all_data *data, int clock, int frame_rate)
{
	pos	p;

	if (clock % frame_rate == 0)
	{
		get_cordonates(data->map.map, &p, 'P');
		if (data->keys[right].status[press] == 1)
			player_mouver(p, 1, 0, data);
		else if (data->keys[up].status[press] == 1)
			player_mouver(p, 0, -1, data);
		else if (data->keys[down].status[press] == 1)
			player_mouver(p, 0, 1, data);
		else if (data->keys[left].status[press] == 1)
			player_mouver(p, -1, 0, data);
	}
}

void	set_exit(char **map)
{
	pos	p;

	get_cordonates(map, &p, 'E');
	if (p.x == -1)
		return ;
	map[p.x][p.y] = 'G';
}

void	total_clean(all_data *data)
{
	free_map(data->map.map);
	images_destroyer(data->img, data->mlx.mlx);
	mlx_clear_window(data->mlx.mlx,data->mlx.mlx);
	mlx_destroy_window(data->mlx.mlx,data->mlx.mlx);
	free(data->mlx.mlx);
}
/////free and exit and !NULL
void	finish_game(all_data *data, int i)
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
	if (i == 1)
	{
		ft_printf("---You lose --enemy touched you---");
		exit(0);
	}
	if (i == 2)
	{
		ft_printf("---Exited with escape botton---");
		exit(0);
	}
	if (i == 3)
	{
		ft_printf("---You lose --you entered into an enemy LOL---");
		exit(0);
	}
	if (i == 4)
	{
		ft_printf("---Exited from cross window's frame---");
		exit(0);
	}
}
///////

void	map_modifier(all_data *data, int clock)
{
	enemy_modifier(data, clock, 50);
	player_modifier(data, clock, 5);
	finish_game(data, 0);
}
