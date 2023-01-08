/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-key_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:16:56 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 19:25:01 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_press_modifier(all_data *data, int p)
{
	data->keys[p].status[0] = 1;
	data->keys[p].status[1] = 0;
}

void	key_release_modifier(all_data *data, int p)
{
	data->keys[p].status[0] = 0;
	data->keys[p].status[1] = 1;
}

int	key_press(int keycode, all_data *data)
{
	pos	p;

	get_cordonates(data->map.map, &p, 'P');
	if (keycode == D)
		key_press_modifier(data, right);
	if (keycode == W)
		key_press_modifier(data, up);
	if (keycode == S)
		key_press_modifier(data, down);
	if (keycode == A)
		key_press_modifier(data, left);
	if (keycode == ESC)
		finish_game(data, 2);
	return (0);
}

int	key_release(int keycode, all_data *data)
{
	pos	p;

	get_cordonates(data->map.map, &p, 'P');
	if (keycode == D)
		key_release_modifier(data, right);
	if (keycode == W)
		key_release_modifier(data, up);
	if (keycode == S)
		key_release_modifier(data, down);
	if (keycode == A)
		key_release_modifier(data, left);
	return (0);
}
