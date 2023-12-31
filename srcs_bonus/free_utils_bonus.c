/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:04:16 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/29 16:21:06 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	free_init_data(t_data *data)
{
	int	i;

	i = -1;
	free(data->player);
	free(data->dda);
	free(data->time);
	free(data->sprites->buffer);
	free(data->sprites);
	while (++i <= 16)
		free(data->imgs[i]);
	free(data->imgs);
	free(data);
}

int	free_on_exit(t_data *data)
{
	int		i;
	t_list	*temp01;
	t_list	*temp02;

	mlx_destroy_window(data->mlx, data->mlx_win);
	temp01 = data->map->item;
	while (temp01)
	{
		temp02 = temp01;
		free(temp01->content);
		temp01 = temp01->next;
		free(temp02);
	}
	i = -1;
	if (data->map && data->map->map)
		while (data->map->map[++i])
			free(data->map->map[i]);
	free(data->map->map);
	doublelst_free(&data->map->spawn);
	free_init_data(data);
	exit(0);
}
