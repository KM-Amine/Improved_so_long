/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_animator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:55:06 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/05 15:40:02 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*path_generator(int file, int dir)
{
	char	*file_path;
	char	*dir_path;
	char	*path;
	char	*full;

	file_path = ft_itoa(file);
	dir_path = ft_itoa(dir);
	path = ft_strjoin("./images/", dir_path);
	full = ft_strjoin(path, "/");
	free(path);
	path = ft_strjoin(full, file_path);
	free(full);
	full = ft_strjoin(path, ".xpm");
	free(file_path);
	free(dir_path);
	free(path);
	return (full);
}

void	images_generator(image_info *img, void *mlx)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 10)
		{
			path = path_generator(i, j);
			//ft_printf("%s\n", path);
			img[j].ptr[i] = mlx_xpm_file_to_image(mlx, path,
					&img[5].resolution.x, &img[5].resolution.y);
			free(path);
			j++;
		}
		i++;
	}
	// img[background].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-0.xpm",&img[0].resolution.x,&img[0].resolution.y);
	// img[wall].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-1.xpm",&img[2].resolution.x,&img[2].resolution.y);
	// img[collectibales].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-2.xpm",&img[4].resolution.x,&img[4].resolution.y);
	// img[map_exit].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-3.xpm",&img[3].resolution.x,&img[3].resolution.y);
	// img[go].ptr[0]=mlx_xpm_file_to_image(mlx,"./images/-4.xpm",&img[5].resolution.x,&img[5].resolution.y);
}
void	images_destroyer(image_info *img, void *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx, img[i].ptr);
	}
}

void	image_animation(int element, int frame_rate, image_info *img,
		void **image_set, int clock)
{
	static int	count[7];

	if (clock % frame_rate == 0)
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
	static int clock;
	int i;

	i = 0;
	while (i < 7)
	{
		image_animation(i, 4, img, image_set, clock);
		i++;
	}
	clock++;
}