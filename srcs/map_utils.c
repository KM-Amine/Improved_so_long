/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:39:12 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:55:23 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_creator(char	**map, int i, char *str, int fd)
{
	int	j;

	j = 0;
	while (j < i)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free_map(map);
			exit(EXIT_FAILURE);
		}
		map[j] = ft_strtrim(str, "\n");
		if (!map[j])
		{
			free_map(map);
			free(str);
			exit(EXIT_FAILURE);
		}
		free(str);
		j++;
	}
}

char	**read_map(char *file)
{
	char	*str;
	int		fd;
	int		i;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	map = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	map_creator(map, i, str, fd);
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**map_copy(char **map)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	copy = (char **)ft_calloc(i + 1, sizeof(char **));
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = ft_strdup(map[j]);
		if (!copy[j])
			return (NULL);
		j++;
	}
	return (copy);
}

void	get_dimentions(char **map, t_pos *cordonates)
{
	cordonates->y = 0;
	cordonates->x = ft_strlen(map[0]);
	while (map[cordonates->y])
	{
		cordonates->y++;
	}
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
