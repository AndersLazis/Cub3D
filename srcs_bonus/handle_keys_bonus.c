/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:04:31 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/29 16:21:26 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	spawn_changer(int key, t_data *data)
{
	if (key == UP_KEY)
	{
		data->map->spawn = data->map->spawn->next;
		create_spawn(data);
		create_plane(data, data->map->dir_spawn);
	}
	if (key == DOWN_KEY)
	{
		data->map->spawn = data->map->spawn->prev;
		create_spawn(data);
		create_plane(data, data->map->dir_spawn);
	}
}

int	exit_keys(int key, t_data *data)
{
	if (key == LEFT_KEY)
		data->player->rot = 0;
	if (key == RIGHT_KEY)
		data->player->rot = 0;
	if (key == LEFT_KEY)
		data->player->rot = 0;
	if (key == RIGHT_KEY)
		data->player->rot = 0;
	if (key == W_KEY)
		data->player->de_y = 0;
	if (key == S_KEY)
		data->player->de_y = 0;
	if (key == D_KEY)
		data->player->de_x = 0;
	if (key == A_KEY)
		data->player->de_x = 0;
	return (0);
}

void	dir_key(t_data *data)
{
	if (data->map->map[(int)(data->player->pos_x - 1.0)] \
		[(int)(data->player->pos_y)] == 'D')
		data->map->map[(int)(data->player->pos_x - 1.0 + data->player->dir_x \
		* data->player->de_y)][(int)(data->player->pos_y)] = '0';
	else if (data->map->map[(int)(data->player->pos_x + 1.0)] \
		[(int)(data->player->pos_y)] == 'D')
		data->map->map[(int)(data->player->pos_x + 1.0 + data->player->dir_x \
		* data->player->de_y)][(int)(data->player->pos_y)] = '0';
	else if (data->map->map[(int)(data->player->pos_x)] \
		[(int)(data->player->pos_y + 1.0)] == 'D')
		data->map->map[(int)(data->player->pos_x + data->player->dir_x \
		* data->player->de_y)][(int)(data->player->pos_y + 1.0)] = '0';
	else if (data->map->map[(int)(data->player->pos_x)] \
		[(int)(data->player->pos_y - 1.0)] == 'D')
		data->map->map[(int)(data->player->pos_x + data->player->dir_x \
		* data->player->de_y)][(int)(data->player->pos_y - 1.0)] = '0';
}

int	handle_keys(int key, t_data *data)
{
	if (key == ESC)
		free_on_exit(data);
	if (key == E_KEY)
		dir_key(data);
	if (key == W_KEY)
		data->player->de_y = 0.07;
	if (key == S_KEY)
		data->player->de_y = -0.07;
	if (key == D_KEY)
		data->player->de_x = 0.07;
	if (key == A_KEY)
		data->player->de_x = -0.07;
	if (key == LEFT_KEY)
		data->player->rot = 0.07;
	if (key == RIGHT_KEY)
		data->player->rot = -0.07;
	spawn_changer(key, data);
	return (0);
}
