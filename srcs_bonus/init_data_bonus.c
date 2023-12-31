/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:37:07 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/29 16:21:30 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

/*initializes the t_player structure within the t_data structure*/
void	init_player(t_data *data)
{
	data->player->de_x = 0;
	data->player->de_y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	data->player->player_x = 0;
	data->player->player_y = 0;
	data->player->rot = 0;
	data->player->total_rots = 0;
}

/*initializes xmp files for textures*/
void	init_xpm(t_data *data, int i, char *path)
{
	data->imgs[i]->p_img = mlx_xpm_file_to_image(data->mlx,
			path, &data->imgs[i]->width, &data->imgs[i]->height);
	if (!(data->imgs[i]->p_img))
		exit(write_error("error: map:\nfailed to load xpm\n"));
	data->imgs[i]->p_img = mlx_get_data_addr(data->imgs[i]->p_img,
			&data->imgs[i]->bt, &data->imgs[i]->s_line, &data->imgs[i]->endian);
}

/*initializes various components and structures within t_data structure*/
int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H, "cub3d");
	data->p_img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	data->player = malloc(sizeof(t_player));
	data->dda = malloc(sizeof(t_dda));
	data->time = malloc(sizeof(t_time));
	data->imgs = malloc(sizeof(t_imgs *) * 17);
	if (!data->mlx || !data->mlx_win || !data->player
		|| !data->dda || !data->time || !data->imgs)
		return (1);
	while (i <= 16)
	{
		data->imgs[i] = malloc(sizeof(t_imgs));
		if (!data->imgs[i])
			return (1);
		i++;
	}
	data->sprites = malloc(sizeof(t_sprites));
	data->sprites->buffer = malloc(sizeof(double) * (WINDOW_W + 1));
	data->imgs[0]->p_img = mlx_get_data_addr(data->p_img, &data->imgs[0]->bt, \
		&data->imgs[0]->s_line, &data->imgs[0]->endian);
	return (0);
}
