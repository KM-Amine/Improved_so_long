/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-enemy_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:38:33 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 18:58:15 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_mouver(all_data *data, pos *p, int x, int y)
{
	if (ft_strchr("P", data->map.map[p->y + y][p->x + x]))
		finish_game(data, 1);
	if (ft_strchr("1EGT", data->map.map[p->y + y][p->x + x]) == NULL)
	{
		data->map.map[p->y][p->x] = '0';
		data->map.map[p->y + y][p->x + x] = 'T';
		p->y = p->y + y;
		p->x = p->x + x;
	}
}

void	enemy_modifier(all_data *data, int clock, int frame_rate)
{
	int		count;
	enemy	zero;

	enemy_direction(data->map.map, data);
	ft_bzero(&zero, sizeof(enemy));
	count = 0;
	if (clock % frame_rate == 0)
	{
		while (ft_memcmp(&(data->enemy[count]), &zero, sizeof(enemy)))
		{
			if (data->enemy[count].direction == DOWNRIGHT)
				enemy_mouver(data, &data->enemy[count].p, 1, 1);
			else if (data->enemy[count].direction == DOWNLEFT)
				enemy_mouver(data, &data->enemy[count].p, -1, 1);
			else if (data->enemy[count].direction == UPLEFT)
				enemy_mouver(data, &data->enemy[count].p, -1, -1);
			else if (data->enemy[count].direction == UPRIGHT)
				enemy_mouver(data, &data->enemy[count].p, 1, -1);
			count++;
		}
	}
}

void	enemy_direction(char **map, all_data *data)
{
	enemy	*en;
	int		count;
	enemy	zero;

	ft_bzero(&zero, sizeof(enemy));
	count = 0;
	en = data->enemy;
	while (ft_memcmp(&en[count], &zero, sizeof(enemy)))
	{
		if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x]))
			up_direction(map, data, en, count);
		else if (ft_strchr("1EGCT", map[en[count].p.y][en[count].p.x + 1]))
			right_direction(map, data, en, count);
		else if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x]))
			down_direction(map, data, en, count);
		else if (ft_strchr("1EGCT", map[en[count].p.y][en[count].p.x - 1]))
			left_direction(map, data, en, count);
		else
			extreme_checker(data, map, en, count);
		count++;
	}
}
