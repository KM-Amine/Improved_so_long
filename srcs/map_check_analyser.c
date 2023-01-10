/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_analyser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:56:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 18:02:03 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_structure(t_map_check *check, char **map)
{
	t_map_check	zero;

	ft_bzero(&zero, sizeof(t_map_check));
	rectangular_map(check, map);
	stranger_characters(check, map);
	minimum_characters(check, map);
	closed_map(check, map);
	if (ft_memcmp(check, &zero, sizeof(t_map_check)) != 0)
	{
		free_map(map);
		error_exit_function(check);
	}
}

void	second_handler(char **copy1, char **copy2, t_map_check *check,
		char **map)
{
	copy2 = map_copy(copy1);
	if (!copy2)
	{
		free_map(map);
		free_map(copy1);
		exit(EXIT_FAILURE);
	}
	free_map(copy1);
	valid_path(check, copy2, 1);
	free_map(copy2);
}

void	valid_path_handler(t_map_check *check, char **map)
{
	char		**copy1;
	char		**copy2;
	t_map_check	zero;

	copy2 = NULL;
	ft_bzero(&zero, sizeof(t_map_check));
	copy1 = map_copy(map);
	if (!copy1)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	valid_path(check, copy1, 0);
	second_handler(copy1, copy2, check, map);
	if (ft_memcmp(check, &zero, sizeof(t_map_check)) != 0)
	{
		free_map(map);
		error_exit_function(check);
	}
}

int	elment_counter(char **map, char c)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

void	get_cordonates(char **map, t_pos *cordonates, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	cordonates->x = -1;
	cordonates->y = -1;
	while (map[i])
	{
		ptr = ft_strchr(map[i], c);
		if (ptr != NULL)
		{
			cordonates->y = i;
			cordonates->x = ptr - map[i];
			break ;
		}
		i++;
	}
}
