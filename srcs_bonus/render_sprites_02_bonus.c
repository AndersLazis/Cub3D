/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_02_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:00:52 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/30 09:45:07 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	set_sprite_stripe(t_data *data)
{
	data->sprites->stripe = data->sprites->draw_start_x;
}

void	sprites_calc(t_data *data, double x, double y)
{
	calculate_sprite_screen_coords(data, x, y);
	set_sprite_stripe(data);
}

void	draw_sprites_calc(t_data *data)
{
	data->sprites->texture_x = (int)(256 * (data->sprites->stripe - \
			(-data->sprites->sprite_width / 2 + data->sprites->spritescreen_x)) \
				* data->imgs[data->time->n_frame]->width / \
		data->sprites->sprite_width) / 256;
}

void	frame_timer(t_data *data, double x, double y)
{
	clock_t	end;
	double	time;

	end = clock();
	time = (double)(end - data->time->start) / CLOCKS_PER_SEC;
	if (data->time->n_frame == 12)
		data->time->n_frame = 6;
	if ((int)(ceil(time)) % 1 == 0 && data->time->n_frame != 12)
	{
		if (data->time->tmp != (int)(ceil(time)))
		{
			data->time->n_frame++;
			data->time->tmp = (int)(ceil(time));
		}
	}
	data->sprites->invdent = 1.0 / (data->player->player_x \
		* data->player->dir_y - data->player->dir_x * data->player->player_y);
	data->sprites->transf_x = (1.0 / (data->player->player_x \
		* data->player->dir_y - data->player->dir_x * data->player->player_y)) \
		* (data->player->dir_y * (x - data->player->pos_x) \
		- data->player->dir_x * (y - data->player->pos_y));
}

void	calculate_sprite_dimensions(t_data *data)
{
	data->sprites->sprite_height = \
		abs((int)(WINDOW_H / (data->sprites->transf_y))) / 3;
	data->sprites->draw_start_y = \
		-data->sprites->sprite_height / 2 \
		+ WINDOW_H / 2 + data->sprites->v_movescreen;
	if (data->sprites->draw_start_y < 0)
		data->sprites->draw_start_y = 0;
	data->sprites->draw_end_y = \
		data->sprites->sprite_height / 2 \
		+ WINDOW_H / 2 + data->sprites->v_movescreen;
	if (data->sprites->draw_end_y >= WINDOW_H)
		data->sprites->draw_end_y = WINDOW_H - 1;
	data->sprites->sprite_width = \
		abs((int)(WINDOW_H / (data->sprites->transf_y))) / 3;
	data->sprites->draw_start_x = \
		-data->sprites->sprite_width / 2 + data->sprites->spritescreen_x;
	if (data->sprites->draw_start_x < 0)
		data->sprites->draw_start_x = 0;
	data->sprites->draw_end_x = \
		data->sprites->sprite_width / 2 + data->sprites->spritescreen_x;
	if (data->sprites->draw_end_x >= WINDOW_W)
		data->sprites->draw_end_x = WINDOW_W - 1;
}
