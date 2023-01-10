/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:00:18 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:58:49 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	contamination(char **map, t_pos p, int *count, char *set)
{
	if (ft_strchr(set, map[p.y][p.x + 1]) != 0)
	{
		*count = 1;
		map[p.y][p.x + 1] = 'Z';
	}
	if (ft_strchr(set, map[p.y][p.x - 1]) != 0)
	{
		*count = 1;
		map[p.y][p.x - 1] = 'Z';
	}
	if (ft_strchr(set, map[p.y + 1][p.x]) != 0)
	{
		*count = 1;
		map[p.y + 1][p.x] = 'Z';
	}
	if (ft_strchr(set, map[p.y - 1][p.x]) != 0)
	{
		*count = 1;
		map[p.y - 1][p.x] = 'Z';
	}
}

int	go_out_checker(int i, char **map, t_pos p)
{
	if (i == 1)
	{
		if (ft_strchr("EPC", map[p.x][p.y]) != 0)
			return (-1);
	}
	else if (i == 0)
	{
		if (ft_strchr("PC", map[p.x][p.y]) != 0)
			return (-1);
	}
	return (1);
}

int	exit_check(char **map, int i)
{
	t_char_cont	c;
	t_pos		p;
	int			len;

	ft_bzero(&c, sizeof(t_char_cont));
	p.x = 0;
	while (map[p.x])
	{
		p.y = 0;
		len = ft_strlen(map[p.x]);
		while (p.y < len)
		{
			if (go_out_checker(i, map, p) == -1)
				return (0);
			p.y++;
		}
		p.x++;
	}
	return (1);
}

void	contamination_process(int b, char **map, int	*end_counter, t_pos	p)
{
	if (map[p.y][p.x] == 'P')
		map[p.y][p.x] = 'Z';
	if (map[p.y][p.x] == 'Z')
	{
		if (b == 1)
			contamination(map, p, end_counter, "C0E");
		else
			contamination(map, p, end_counter, "C0");
	}
}

void	valid_path(t_map_check *check, char **map, int b)
{
	t_pos	p;
	int		end_counter;

	end_counter = 0;
	while (1)
	{
		end_counter = 0;
		p.y = 0;
		while (map[p.y])
		{
			p.x = 0;
			while (map[p.y][p.x])
			{
				contamination_process(b, map, &end_counter, p);
				p.x++;
			}
			p.y++;
		}
		if (end_counter == 0)
			break ;
	}
	if (exit_check(map, b) == 0 && b == 0)
		check->no_exit = -1;
	else if (exit_check(map, b) == 0 && b == 1)
		check->with_exit = -1;
}
