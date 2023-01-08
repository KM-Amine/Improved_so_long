/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:54:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 14:54:31 by mkhellou         ###   ########.fr       */
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
/////free and exit and !NULL

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
///////

void	player_mouver(pos p, int x, int y, all_data *data)
{
	static int	i;

	if (data->map.map[p.y + y][p.x + x] == 'T')
	{
		ft_printf("You lose --you entered into an enemy LOL--");
		exit(0);
	}
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
///////

void	map_modifier(all_data *data, int clock)
{
	enemy_direction(data->map.map, data);
	enemy_modifier(data, clock, 50);
	player_modifier(data, clock, 5);
	finish_game(data);
}
