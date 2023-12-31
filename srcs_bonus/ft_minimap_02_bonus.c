/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_02_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:10:14 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/29 09:13:50 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	draw_minimap(t_data *data)
{
	draw_back_layer(data);
	draw_square(data, 100, 100, create_trgb(0, 0, 255, 0));
}

void	draw_walls_doors(t_data *data, int i, int j)
{
	draw_square(data, 100 - ((int)data->player->pos_x - j) \
		* 20, 100 - ((int)data->player->pos_y - i) * 20, \
		(create_trgb(0, 255, 0, 0)));
}

void	draw_bombs(t_data *data, int i, int j)
{
	draw_square(data, 100 - ((int)data->player->pos_x - j) \
		* 20, 100 - ((int)data->player->pos_y - i) * 20, \
		(create_trgb(0, 0, 0, 255)));
}

void	ft_minimap(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	draw_minimap(data);
	while (data->map->map[j])
	{
		i = 0;
		while (data->map->map[j][i])
		{
			if (data->player->pos_x - j < 5 && (int)data->player->pos_x - j > \
				-4 && (int)data->player->pos_y - i < 5 \
				&& (int)data->player->pos_y - i > -4)
			{
				if (data->map->map[j][i] == '1' || data->map->map[j][i] == 'D')
					draw_walls_doors(data, i, j);
				if (data->map->map[j][i] == 'B')
					draw_bombs(data, i, j);
			}
			i++;
		}
		j++;
	}
}
