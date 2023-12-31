/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:19:17 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/30 11:10:46 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	create_sprite(t_data *data, int y)
{
	int	i;
	int	j;

	j = data->imgs[data->time->n_frame]->s_line * data->sprites->texture_y
		+ data->sprites->texture_x * data->imgs[data->time->n_frame]->bt / 8;
	if (data->imgs[data->time->n_frame]->p_img[j] == 0 && \
		data->imgs[data->time->n_frame]->p_img[j + 1] == 0 && \
		data->imgs[data->time->n_frame]->p_img[j + 2] == 0)
		return ;
	i = data->sprites->stripe * data->imgs[0]->bt
		/ 8 + data->imgs[0]->s_line * y;
	data->imgs[0]->p_img[i] = data->imgs[data->time->n_frame]->p_img[j];
	data->imgs[0]->p_img[++i] = data->imgs[data->time->n_frame]->p_img[++j];
	data->imgs[0]->p_img[++i] = data->imgs[data->time->n_frame]->p_img[++j];
}

void	calculate_sprite_screen_coords(t_data *data, double x, double y)
{
	data->sprites->transf_y = \
		(1.0 / (data->player->player_x * data->player->dir_y - \
			data->player->dir_x * data->player->player_y)) * \
			(-data->player->player_y * (x - data->player->pos_x) + \
				data->player->player_x * (y - data->player->pos_y));
	data->sprites->v_movescreen = 120 / data->sprites->transf_y;
	data->sprites->spritescreen_x = \
		(int)((WINDOW_W / 2) * (1 + data->sprites->transf_x / \
			data->sprites->transf_y));
	calculate_sprite_dimensions(data);
}

void	render_calculations(t_data *data, double x, double y)
{
	frame_timer(data, x, y);
	sprites_calc(data, x, y);
}

void	draw_sprites(t_data *data, double x, double y)
{
	int	i;

	render_calculations(data, x, y);
	while (++data->sprites->stripe < data->sprites->draw_end_x)
	{
		data->sprites->texture_x = (int)(256 * (data->sprites->stripe - \
			(-data->sprites->sprite_width / 2 + data->sprites->spritescreen_x)) \
				* data->imgs[data->time->n_frame]->width / \
		data->sprites->sprite_width) / 256;
		if (data->sprites->transf_y > 0 && data->sprites->stripe > 0 && \
			data->sprites->stripe < WINDOW_W && data->sprites->transf_y \
			< data->sprites->buffer[data->sprites->stripe])
		{
			y = data->sprites->draw_start_y;
			while (++y < data->sprites->draw_end_y)
			{
				i = (y - data->sprites->v_movescreen) * 256 - WINDOW_H \
					* 128 + data->sprites->sprite_height * 128;
				data->sprites->texture_y = ((i * \
					data->imgs[data->time->n_frame]->height) / \
						data->sprites->sprite_height) / 256;
				create_sprite(data, y);
			}
		}
	}
}

void	render_sprites(t_data *data)
{
	t_list	*temp;
	t_items	*content;

	temp = data->map->item;
	while (temp)
	{
		content = (t_items *)temp->content;
		if (content->pos_y == (int)data->player->pos_x && \
			content->pos_x == (int)data->player->pos_y)
		{
			data->n_taken++;
			content->pos_x = -1;
			content->pos_y = -1;
			data->map->map[(int)data->player->pos_x] \
			[(int)data->player->pos_y] = '0';
		}
		if (!(content->pos_x == -1 && content->pos_y == -1))
			draw_sprites(data, ((double)(content)->pos_y) + \
				0.5, (double)(content)->pos_x + 0.5);
		temp = temp->next;
	}
}
