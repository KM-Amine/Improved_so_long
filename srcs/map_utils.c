/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:39:12 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 18:02:26 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(char *file)
{
	char	*str;
	int		fd;
	int		i;
	char	**map;
	int		j;

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
	close(fd);
	map = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	j = 0;
	while (j < i)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free_map(map);
			return (0);
		}
		map[j] = ft_strtrim(str, "\n");
		if (!map[j])
		{
			free_map(map);
			free(str);
			return (NULL);
		}
		free(str);
		j++;
	}
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

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (j < i)
	{
		ft_printf("%s\n", map[j]);
		j++;
	}
}

void	get_dimentions(char **map, pos *cordonates)
{
	cordonates->y = 0;
	cordonates->x = ft_strlen(map[0]);
	while (map[cordonates->y])
	{
		cordonates->y++;
	}
}

void	get_cordonates(char **map, pos *cordonates, char c)
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
