/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-image_animator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:55:06 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/10 17:50:21 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	image_animation(int element, t_timing t, t_image_info *img,
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

void	image_modifier(t_image_info *img, void **image_set)
{
	static t_timing	t;
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
