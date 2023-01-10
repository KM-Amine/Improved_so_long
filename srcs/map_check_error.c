/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:43:06 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 15:16:23 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

map_info	map_checker(int av, char **ac)
{
	map_info	map;

	if (av != 2)
	{
		ft_putstr_fd("Error\n invalid number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	file_name_checker(ac[1]);
	ft_printf("Valid file name\n");
	map.map = read_map(ac[1]);
	if (!map.map)
		exit(EXIT_FAILURE);
	map_error_handling(map.map);
	check_cordonates(map.map, &map.resolution);
	return (map);
}

void	map_error_handling(char **map)
{
	map_check	check;

	ft_bzero(&check, sizeof(map_check));
	map_structure(&check, map);
	valid_path_handler(&check, map);
	ft_printf("Your map is valid\n");
}

void	file_name_checker(char *str)
{
	int		fd;
	int		len;
	char	*ptr;

	len = 0;
	if (ft_strlen(str) > 4)
		len = ft_strlen(str) - 4;
	ptr = str + len;
	if (ft_strncmp(".ber", ptr, 4) != 0 || ft_strlen(str) < 5)
	{
		ft_putstr_fd("Error\nInvalid file extention\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("Error\nUnable to open file\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
}

void	check_cordonates(char **map, pos *cordonates)
{
	int	i;

	i = 0;
	get_dimentions(map, cordonates);
	if (cordonates->x * SPRITE_X > WINDOW_X)
	{
		i = 1;
		ft_putstr_fd("map x  is too large\n", 2);
	}
	if ((cordonates->y + 1) * SPRITE_Y > WINDOW_Y)
	{
		i = 1;
		ft_putstr_fd("map y  is too large\n", 2);
	}
	if (i == 1)
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("Size screen is valid\n");
}

void	error_exit_function(map_check *check)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid map :\n", 2);
	if (check->rectangular == -1)
		ft_putstr_fd("- map is not rectangular\n", 2);
	if (check->stranger_characters == -1)
		ft_putstr_fd("- map has a stranger character\n", 2);
	if (check->minimum_characters == -1)
		ft_putstr_fd("- wronge number of coins ,exit and start\n", 2);
	if (check->closed == -1)
		ft_putstr_fd("- the map is not closed by walls\n", 2);
	if (check->with_exit == -1)
		ft_putstr_fd("- unvalid path :the exit can't be reached\n", 2);
	if (check->no_exit == -1)
		ft_putstr_fd("- unvalid path :the coins can't be reached\n", 2);
	exit(EXIT_FAILURE);
}
