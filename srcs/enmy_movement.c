/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enmy_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:38:33 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/06 17:33:54 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_spawner(map_info *map)
{
	int	i;
	int x;
	int y;
	int count;

	i = 0;
	count = 0;
	while (count < map->resolution.y/3)
	{
		srand(clock());
		y = rand()%map->resolution.y;
		srand(clock());
		x = rand()%map->resolution.y;
		if (ft_strchr("0", map->map[y][x]))
		{
			map->map[y][x] = 'T';
			count++;
		}
		i++;
	}
}

// work on this shit 
void	enemy_respawner(map_info *map,enemy *enemy)
{
	int x;
	int y;
	int count;

	map->map[enemy->p.y][enemy->p.x]='0';
	count = 0;
	while (count<1)
	{
		srand(clock());
		y = rand()%map->resolution.y;
		srand(clock());
		x = rand()%map->resolution.x;
		if (ft_strchr("0", map->map[y][x]))
		{
			count++;
			map->map[y][x] = 'T';
			enemy->p.y = y;
			enemy->p.x = x;
			return;
		}
	}
}

void	enemy_collector(all_data *data)
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

void	enemy_mouver(char **map, pos *p, int x, int y)
{
	if (ft_strchr("1EGT", map[p->y + y][p->x + x]) == NULL)
	{
		map[p->y][p->x] = '0';
		map[p->y + y][p->x + x] = 'T';
		p->y = p->y + y;
		p->x = p->x + x;
	}
}

void	enemy_direction(char **map, all_data *data)
{
	enemy	*en;
	int		count;
	enemy zero;
	int check;
	
	check =0;
	ft_bzero(&zero,sizeof(enemy));
	count = 0;
	en = data->enemy;
	while (ft_memcmp(&en[count],&zero,sizeof(enemy)))
	{
		print_map(map);
		respawn_detector(data,&en[count]);
		if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x]))
		{
			if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x + 1]) || ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x - 1]))
			{
				enemy_respawner(&(data->map),&en[count]);
			}
			if (en[count].direction == UPLEFT)
				en[count].direction =  DOWNLEFT ;
			else if (en[count].direction == UPRIGHT)
				en[count].direction =  DOWNRIGHT;
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y][en[count].p.x + 1]))
		{
			if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x - 1]) || ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x - 1]))
			{
				enemy_respawner(&(data->map),&en[count]);
			}
			if (en[count].direction == UPRIGHT)
				en[count].direction = UPLEFT;
			else if (en[count].direction ==  DOWNRIGHT)
				en[count].direction =  DOWNLEFT;
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x]))
		{
			if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x - 1]) || ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x + 1]))				
			{
				enemy_respawner(&(data->map),&en[count]);
			}
			if (en[count].direction ==  DOWNRIGHT)
				en[count].direction = UPRIGHT;
			else if (en[count].direction ==  DOWNLEFT)
				en[count].direction = UPLEFT;
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y][en[count].p.x - 1]))
		{
			if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x + 1]) || ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x + 1]))
			{
				enemy_respawner(&(data->map),&en[count]);
			}
			if (en[count].direction ==  DOWNLEFT)
				en[count].direction =  DOWNRIGHT;
			else if (en[count].direction == UPLEFT)
					en[count].direction = UPRIGHT;
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x + 1]))
		{
			enemy_respawner(&(data->map),&en[count]);
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x + 1]))
		{
			enemy_respawner(&(data->map),&en[count]);
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x - 1]))
		{
			enemy_respawner(&(data->map),&en[count]);
		}
		else if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x - 1]))
		{
			enemy_respawner(&(data->map),&en[count]);
		}
		count ++;
	}
}



void	enemy_modifier(all_data *data, int clock, int frame_rate)
{
	int count;
	enemy zero;
	
	ft_bzero(&zero,sizeof(enemy));
	
	count = 0;

	if (clock % frame_rate == 0)
	{
		while (ft_memcmp(&(data->enemy[count]),&zero,sizeof(enemy)))
		{
			if (data->enemy[count].direction == DOWNRIGHT)
				enemy_mouver(data->map.map, &data->enemy[count].p, 1, 1);
			else if (data->enemy[count].direction == DOWNLEFT)
				enemy_mouver(data->map.map, &data->enemy[count].p, -1, 1);
			else if (data->enemy[count].direction == UPLEFT)
				enemy_mouver(data->map.map, &data->enemy[count].p, -1, -1);
			else if (data->enemy[count].direction == UPRIGHT)
				enemy_mouver(data->map.map, &data->enemy[count].p, 1, -1);
			count++;
		}
	}
}