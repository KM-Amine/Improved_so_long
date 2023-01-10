/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-image_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:51:17 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 16:52:17 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	first_part(fpath	*p, all_data *data, int dir, int file)
{
	p->file_path = ft_itoa(file);
	if (!p->file_path)
		total_clean(data);
	p->dir_path = ft_itoa(dir);
	if (!p->dir_path)
	{
		free(p->file_path);
		total_clean(data);
	}
	p->path = ft_strjoin("./images/", p->dir_path);
	if (!p->path)
	{
		free(p->file_path);
		free(p->dir_path);
		total_clean(data);
	}
}

void	second_part(fpath	*p, all_data *data)
{
	p->path = ft_strjoin(p->full, p->file_path);
	if (!p->path)
	{
		free(p->file_path);
		free(p->full);
		free(p->dir_path);
		total_clean(data);
	}
	free(p->full);
	p->full = ft_strjoin(p->path, ".xpm");
	if (!p->full)
	{
		free(p->file_path);
		free(p->path);
		free(p->dir_path);
		total_clean(data);
	}
	free(p->file_path);
	free(p->dir_path);
	free(p->path);
}

char	*path_generator(int file, int dir, all_data *data)
{
	fpath	p;

	ft_bzero(&p, sizeof(fpath));
	first_part(&p, data, dir, file);
	p.full = ft_strjoin(p.path, "/");
	if (!p.full)
	{
		free(p.file_path);
		free(p.dir_path);
		free(p.path);
		total_clean(data);
	}
	free(p.path);
	second_part(&p, data);
	return (p.full);
}

void	single_image_creator(int i, int j, all_data *data)
{
	char	*path;

	path = path_generator(i, j, data);
	if (open(path, O_RDONLY) == -1)
	{
		free(path);
		return ;
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
