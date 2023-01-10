/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-enemy_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:48:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:47:17 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	extreme_checker(t_all_data *data, char **map, t_enemy *en, int count)
{
	if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x + 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x + 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x - 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x - 1]))
		enemy_respawner(&(data->map), &en[count]);
}

void	up_direction(char **map, t_all_data *data, t_enemy *en, int count)
{
	if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x + 1])
		|| ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x - 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (en[count].direction == UPLEFT)
		en[count].direction = DOWNLEFT;
	else if (en[count].direction == UPRIGHT)
		en[count].direction = DOWNRIGHT;
}

void	right_direction(char **map, t_all_data *data, t_enemy *en, int count)
{
	if (ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x - 1])
		|| ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x - 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (en[count].direction == UPRIGHT)
		en[count].direction = UPLEFT;
	else if (en[count].direction == DOWNRIGHT)
		en[count].direction = DOWNLEFT;
}

void	down_direction(char **map, t_all_data *data, t_enemy *en, int count)
{
	if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x - 1])
		|| ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x + 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (en[count].direction == DOWNRIGHT)
		en[count].direction = UPRIGHT;
	else if (en[count].direction == DOWNLEFT)
		en[count].direction = UPLEFT;
}

void	left_direction(char **map, t_all_data *data, t_enemy *en, int count)
{
	if (ft_strchr("1EGCT", map[en[count].p.y - 1][en[count].p.x + 1])
		|| ft_strchr("1EGCT", map[en[count].p.y + 1][en[count].p.x + 1]))
		enemy_respawner(&(data->map), &en[count]);
	else if (en[count].direction == DOWNLEFT)
		en[count].direction = DOWNRIGHT;
	else if (en[count].direction == UPLEFT)
		en[count].direction = UPRIGHT;
}
