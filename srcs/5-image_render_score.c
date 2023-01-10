// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   5-image_render_score.c                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/08 15:14:59 by mkhellou          #+#    #+#             */
// /*   Updated: 2023/01/10 13:20:17 by mkhellou         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/so_long.h"


// char	*score_creator(int i, char c, all_data *data)
// {
// 	char	*tmp;
// 	char	*str;

// 	tmp = ft_itoa(i);
// 	str = NULL;
// 	(void)data;
// 	if (c == 'M')
// 		str = ft_strjoin("Number of movements: ", tmp);
// 		if (!str)
// 		{
// 			//free(tmp);
// 			//total_clean(data);
// 		}
// 	else
// 		str = ft_strjoin("Number of coins left: ", tmp);
// 		if (!str)
// 		{
// 			//free(tmp);
// 			//total_clean(data);
// 		}
// 	//free(tmp);
// 	return (str);
// }

// void	score_printer(int i, int j, all_data *data)
// {
// 	int		mouvement;
// 	char	*mvstr;
// 	int		coins;

// 	mouvement = data->text.mouvement;
// 	coins = data->text.coins;
// 	mvstr = score_creator(mouvement, 'M',data);
// 	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, SPRITE_X / 2, (j
// 			* SPRITE_Y) + SPRITE_Y / 3, 65535, mvstr);
// 	//free(mvstr);
// 	mvstr = score_creator(coins, 'C',data);
// 	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, i * SPRITE_X / 2, (j
// 			* SPRITE_Y) + SPRITE_Y / 3, 65535, mvstr);
// 	//free(mvstr);
// }


// void	score_layer(void **image_set, all_data *data)
// {
// 	int	j;
// 	int	i;

// 	j = data->map.resolution.y;
// 	i = 0;
// 	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
// 	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, image_set[7], i
// 		* SPRITE_X, j * SPRITE_Y);
// 	while (i < data->map.resolution.x)
// 	{
// 		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, image_set[8],
// 			i * SPRITE_X, j * SPRITE_Y);
// 		i++;
// 	}
// 	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, image_set[9], (i
// 			- 1) * SPRITE_X, j * SPRITE_Y);
// 	score_printer(i, j, data);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-image_render_score.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:14:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 18:36:16 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

////--------------------
char	*score_creator(int i, char c)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(i);
	if (c == 'M')
		str = ft_strjoin("Number of movements: ", tmp);
	else
		str = ft_strjoin("Number of coins left: ", tmp);
	free(tmp);
	return (str);
}
////--------------------

void	score_printer(int i, int j, all_data *data)
{
	int		mouvement;
	char	*mvstr;
	int		coins;

	mouvement = data->text.mouvement;
	coins = data->text.coins;
	mvstr = score_creator(mouvement, 'M');
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, SPRITE_X / 2, (j
			* SPRITE_Y) + SPRITE_Y / 3, 65535, mvstr);
	free(mvstr);
	mvstr = score_creator(coins, 'C');
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, i * SPRITE_X / 2, (j
			* SPRITE_Y) + SPRITE_Y / 3, 65535, mvstr);
	free(mvstr);
}
////--------------------

void	score_layer(void **image_set, all_data *data)
{
	int	j;
	int	i;

	j = data->map.resolution.y;
	i = 0;
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, image_set[7], i
		* SPRITE_X, j * SPRITE_Y);
	while (i < data->map.resolution.x)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, image_set[8],
			i * SPRITE_X, j * SPRITE_Y);
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, image_set[9], (i
			- 1) * SPRITE_X, j * SPRITE_Y);
	score_printer(i, j, data);
}