/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enmy_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:38:33 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/17 19:19:05 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_spawner(char **map)
{
	int	i;
	int	j;

	//int count;
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i] + i, '0') && i % 2 == 0)
		{
			j = ft_strchr(map[i] + i, '0') - map[i] + i;
			map[i][j] = 'T';
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
				ft_printf("%d", count);
			}
			j++;
		}
		i++;
	}
}

void	enemy_direction(char **map, all_data *data)
{
	enemy	*en;
	int		count;

	count = 0;
	en = data->enemy;
	if (ft_strchr("1EGTC", map[en[count].p.y - 1][en[count].p.x]))
	{
		if (en[count].direction == 2)
			en[count].direction = 1;
		else if (en[count].direction == 3)
			en[count].direction = 0;
	}
	if (ft_strchr("1EGTC", map[en[count].p.y][en[count].p.x + 1]))
	{
		if (en[count].direction == 3)
			en[count].direction = 2;
		else if (en[count].direction == 0)
			en[count].direction = 1;
	}
	if (ft_strchr("1EGTC", map[en[count].p.y + 1][en[count].p.x]))
	{
		if (en[count].direction == 0)
			en[count].direction = 3;
		else if (en[count].direction == 1)
			en[count].direction = 2;
	}
	if (ft_strchr("1EGTC", map[en[count].p.y][en[count].p.x - 1]))
	{
		if (en[count].direction == 1)
			en[count].direction = 0;
		else if (en[count].direction == 2)
			en[count].direction = 3;
	}
}

void	enemy_mouver(char **map, pos *p, int x, int y)
{
	static int	i;

	ft_printf("%c", map[p->y + x][p->x + x]);
	if (ft_strchr("1EGT", map[p->y + y][p->x + x]) == NULL)
	{
		i++;
		ft_printf("enemy : %d times %d %d \n", i, p->x, p->y);
		map[p->y][p->x] = '0';
		map[p->y + y][p->x + x] = 'T';
		p->y = p->y + y;
		p->x = p->x + x;
	}
}

void	enemy_modifier(all_data *data, int clock, int frame_rate)
{
	int count;

	count = 0;
	if (clock % frame_rate == 0)
	{
		if (data->enemy[count].direction == 0)
			enemy_mouver(data->map.map, &data->enemy[count].p, 1, 1);
		else if (data->enemy[count].direction == 1)
		{
			enemy_mouver(data->map.map, &data->enemy[count].p, -1, 1);
		}
		else if (data->enemy[count].direction == 2)
			enemy_mouver(data->map.map, &data->enemy[count].p, -1, -1);
		else if (data->enemy[0].direction == 3)
			enemy_mouver(data->map.map, &data->enemy[count].p, 1, -1);
	}
}