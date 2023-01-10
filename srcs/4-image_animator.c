/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-image_animator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:55:06 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 13:05:38 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*path_generator(int file, int dir,all_data *data)
{
	char	*file_path;
	char	*dir_path;
	char	*path;
	char	*full;

	file_path = ft_itoa(file);
	if (!file_path)
		total_clean(data);
	dir_path = ft_itoa(dir);
	if (!dir_path)
	{
		free(file_path);
		total_clean(data);
	}
	path = ft_strjoin("./images/", dir_path);
	if (!path)
	{
		free(file_path);
		free(dir_path);
		total_clean(data);
	}
	full = ft_strjoin(path, "/");
	if (!full)
	{
		free(file_path);
		free(dir_path);
		free(path);
		total_clean(data);
	}
	free(path);
	path = ft_strjoin(full, file_path);
	if (!path)
	{
		free(file_path);
		free(full);
		free(dir_path);
		total_clean(data);
	}
	free(full);
	full = ft_strjoin(path, ".xpm");
	if(!full)
	{
		free(file_path);
		free(path);
		free(dir_path);
		total_clean(data);
	}
	free(file_path);
	free(dir_path);
	free(path);
	return (full);
}

void	single_image_creator(int i, int j, all_data *data)
{
	char	*path;

	path = path_generator(i, j,data);
	if (open(path, O_RDONLY) == -1)
	{
		free(path);
		return;
	}
	data->img[j].ptr[i] = mlx_xpm_file_to_image(data->mlx.mlx, path,
			&(data->img[j].resolution.x), &(data->img[j].resolution.y));
	if (!(data->img[j].ptr[i]))
	{
		free(path);
		total_clean(data);
	}
	free(path);
}

void	images_generator(all_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 10)
		{
			single_image_creator(i, j, data);
			j++;
		}
		i++;
	}
}

void	image_animation(int element, timing t, image_info *img,
		void **image_set)
{
	static int	count[10];

	if (t.clock % t.framerate == 0)
	{
		if (img[element].ptr[count[element]] != NULL)
		{
			image_set[element] = img[element].ptr[count[element]];
			count[element]++;
		}
		else
			count[element] = 0;
	}
}

void	image_modifier(image_info *img, void **image_set)
{
	static timing	t;
	int				i;

	i = 0;
	t.framerate = 4;
	while (i < 10)
	{
		image_animation(i, t, img, image_set);
		i++;
	}
	t.clock++;
}
