/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:15:02 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/29 16:21:21 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

int	render_vertical_l(t_data *data, int y, int color, int i)
{
	while (i < y)
	{
		ft_mlx_pixel_put(data->imgs[0], data->dda->screen_x, i, color);
		i++;
	}
	return (i);
}

void	set_texture(t_data *data)
{
	if (data->dda->side == 1 || data->dda->side == 2
		|| data->dda->side == 13 || data->dda->side == 14)
	{
		data->dda->wall_x = data->player->pos_y
			+ data->dda->wall_dist * data->dda->ray_dir_y;
		data->dda->wall_x -= floor(data->dda->wall_x);
		data->dda->text_x = (int)(data->dda->wall_x
				* (double)data->imgs[data->dda->side]->width);
		if (data->dda->ray_dir_x > 0)
			data->dda->text_x = data->imgs[data->dda->side]->width
				- data->dda->text_x - 1;
	}
	else if (data->dda->side == 3 || data->dda->side == 4
		|| data->dda->side == 15 || data->dda->side == 16)
	{
		data->dda->wall_x = data->player->pos_x
			+ data->dda->wall_dist * data->dda->ray_dir_x;
		data->dda->wall_x -= floor(data->dda->wall_x);
		data->dda->text_x = (int)(data->dda->wall_x
				* (double)data->imgs[data->dda->side]->width);
		if (data->dda->ray_dir_y < 0)
			data->dda->text_x = data->imgs[data->dda->side]->width
				- data->dda->text_x - 1;
	}
}

int	get_pixel(t_imgs *imgs, int x, int y)
{
	int	*dest;
	int	color;

	dest = (void *)imgs->p_img + (y * imgs->s_line + x
			* (imgs->bt / 8));
	color = *(int *)dest;
	return (color);
}

int	render_texture(t_data *data, int y)
{
	int	i;
	int	color;

	i = 0;
	set_texture(data);
	data->dda->move = 1.0 * data->imgs[data->dda->side]->height / \
		data->dda->line_height;
	data->dda->text_pos = (data->dda->draw_start - WINDOW_H / 2 \
		+ data->dda->line_height / 2) * data->dda->move;
	while (y < data->dda->draw_end - 1)
	{
		data->dda->text_y = (int)data->dda->text_pos & \
			(data->imgs[data->dda->side]->height - 1);
		data->dda->text_pos += data->dda->move;
		color = get_pixel(data->imgs[data->dda->side],
				data->dda->text_x, data->dda->text_pos);
		ft_mlx_pixel_put(data->imgs[0], data->dda->screen_x, y, color);
		y++;
		i++;
	}
	return (i);
}

void	ft_render(t_data *data)
{
	int	i;

	i = 0;
	data->dda->line_height = (int)(WINDOW_H / data->dda->wall_dist);
	data->dda->draw_start = -data->dda->line_height / 2 + WINDOW_H / 2;
	if (data->dda->draw_start < 0)
		data->dda->draw_start = 0;
	data->dda->draw_end = data->dda->line_height / 2 + WINDOW_H / 2;
	if (data->dda->draw_end > WINDOW_H)
		data->dda->draw_end = WINDOW_H - 1;
	i += render_vertical_l(data, data->dda->draw_start, data->map->c, 0);
	i += render_texture(data, i);
	render_vertical_l(data, WINDOW_H, data->map->f, i);
}
