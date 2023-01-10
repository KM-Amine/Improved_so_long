/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-enemy_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:05:51 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:47:39 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_spawner(t_map_info *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	while (count < map->resolution.y / 3)
	{
		srand(clock());
		y = rand() % map->resolution.y;
		srand(clock());
		x = rand() % map->resolution.y;
		if (ft_strchr("0", map->map[y][x]))
		{
			map->map[y][x] = 'T';
			count++;
		}
	}
}

void	enemy_respawner(t_map_info *map, t_enemy *enemy)
{
	int	x;
	int	y;
	int	count;

	map->map[enemy->p.y][enemy->p.x] = '0';
	count = 0;
	while (count < 1)
	{
		srand(clock());
		y = rand() % map->resolution.y;
		srand(clock());
		x = rand() % map->resolution.x;
		if (ft_strchr("0", map->map[y][x]))
		{
			count++;
			map->map[y][x] = 'T';
			enemy->p.y = y;
			enemy->p.x = x;
			return ;
		}
	}
}

void	enemy_collector(t_all_data *data)
{
	char	**map;
	int		j;
	int		i;
	int		count;

	count = 0;
	map = data->map.map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'T')
			{
				data->enemy[count].p.x = j;
				data->enemy[count].p.y = i;
				count++;
			}
			j++;
		}
		i++;
	}
}
