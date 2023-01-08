/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:16:56 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/08 11:52:47 by mkhellou         ###   ########.fr       */
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

//exit system---------------------
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
	{
		data->keys[4].status[0] = 1;
		exit_free(NULL);
	}
	return (0);
}
//------------------------------

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

void	player_modifier(all_data *data, int clock, int frame_rate)
{
	pos	p;

	if (clock % frame_rate == 0)
	{
		get_cordonates(data->map.map, &p, 'P');
		if (data->keys[right].status[press] == 1)
			player_mouver(p, 1, 0, data);
		else if (data->keys[up].status[press] == 1)
			player_mouver(p, 0, -1, data);
		else if (data->keys[down].status[press] == 1)
			player_mouver(p, 0, 1, data);
		else if (data->keys[left].status[press] == 1)
			player_mouver(p, -1, 0, data);
	}
}
