/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-player_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:18:29 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:49:32 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_mouver(t_pos p, int x, int y, t_all_data *data)
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

void	player_modifier(t_all_data *data, int clock, int frame_rate)
{
	t_pos	p;

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
	t_pos	p;

	get_cordonates(map, &p, 'E');
	if (p.x == -1)
		return ;
	map[p.x][p.y] = 'G';
}

void	win_checker(t_all_data *data)
{
	char	**map;

	map = data->map.map;
	if (elment_counter(map, 'C') == 0)
	{
		set_exit(map);
		if (elment_counter(map, 'G') == 0)
		{
			ft_printf("You won you collected all coins and exited with%d moves",
				data->text.mouvement);
			total_clean(data);
		}
	}
}

void	finish_game(t_all_data *data, int i)
{
	win_checker(data);
	if (i == 1)
		ft_printf("---You lose --enemy touched you---");
	if (i == 2)
		ft_printf("---Exited with escape botton---");
	if (i == 3)
		ft_printf("---You lose --you entered into an enemy LOL---");
	if (i == 4)
		ft_printf("---Exited from cross window's frame---");
	if (i != 0)
		total_clean(data);
}
