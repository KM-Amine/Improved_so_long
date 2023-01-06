/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enmy_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:38:33 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/06 16:09:33 by mkhellou         ###   ########.fr       */
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
	while (count<elment_counter(map->map,'0'))
	{
		srand(clock());
		y = rand()%map->resolution.y;
		srand(clock());
		x = rand()%map->resolution.y;
		if (ft_strchr("0", map->map[y][x]) && i % 3 == 0)
		{
			map->map[y][x] = 'T';
			count++;
		}
		i++;
	}
//	print_map(map->map);
}

// work on this shit 
void	enemy_respawner(map_info *map,enemy *enemy)
{
	int	i;
	int x;
	int y;
	int count;
	i = 0;
//	print_map(map->map);
	map->map[enemy->p.y][enemy->p.x]='0';
//	ft_printf("%d %d\n",enemy->p.y,enemy->p.x);
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
		i++;
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
int respawn_detector(all_data *data,enemy *enemy)
{
	// int x;
	// int y;
	// int count;
	
 	(void)data;
	(void)enemy;
// 	count = 0;
// 	x = enemy->p.x;
// 	y = enemy->p.y;
// //	print_map(data->map.map);
// 	ft_printf("%d-%d\n",x,y);
// 	if(ft_strchr("1EGCT",data->map.map[x+1][y+1]))
//  {
// 	//	ft_printf("fuck\n");	
// 		count++;
// 		ft_printf("\n%d--",count);
// 	}
// 	if(ft_strchr("1EGCT",data->map.map[x-1][y+1]))
// 	{
// 		//ft_printf("fuck");	
// 		count++;
// 		ft_printf("%d--",count);
// 	}
// 	if(ft_strchr("1EGCT",data->map.map[x+1][y-1]))
// 	{
// 	//	ft_printf("fuck,\n");	
// 		count++;
// 		ft_printf("%d--",count);
// 	}
// 	if(ft_strchr("1EGCT",data->map.map[x-1][y-1]))
// 	{
// 	//	ft_printf("fuck\n");	
// 		count++;
// 		ft_printf("%d\n",count);
// 	}
// 	if(count > 0)
// 	{
// 	//	enemy_respawner(&(data->map),enemy);
// 	//	print_map(data->map.map);
// 		return(-1);
// 	}
	return(0);
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