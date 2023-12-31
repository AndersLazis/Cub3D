/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:00:06 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 09:27:02 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static int	free_take_cub(t_files *files, t_map *map)
{
	(void)map;
	ft_free(files->north, files->south, files->west, files->east);
	ft_free(files->c, files->f, files, 0);
	exit(write_error("error: map:\nmalloc failed\n"));
}

/*responsible for extracting the map data from the [tab] array
 * and stores it in the t_map structure*/
int	take_cub(t_files *files, t_map *map, char **tab)
{
	size_t	i;
	size_t	j;

	if (!files->map_begin)
		exit(write_error("error: map:\nerror in map\n"));
	ft_tab_len(files, tab);
	map->map = malloc(sizeof(char *) * (files->tab_len + 1));
	if (!map->map)
		return (free_take_cub(files, map));
	i = files->map_begin;
	j = 0;
	while (tab[i])
	{
		map->map[j] = ft_strdup(tab[i]);
		if (!map->map[j++])
			return (free_take_cub(files, map));
		i++;
	}
	map->map[j] = 0;
	map->map_len = files->tab_len;
	return (0);
}
