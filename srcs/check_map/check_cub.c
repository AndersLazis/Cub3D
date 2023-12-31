/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:08:32 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 09:25:45 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/*responsible for adding items to the game map
 *also handles adding spawn points to t_map*/
int	add_item(t_map *map, int x, int y)
{
	t_items		*item;
	t_doublell	*temp;

	item = malloc(sizeof(t_items));
	if (!item)
		return (1);
	item->type = map->map[y][x];
	item->pos_x = x;
	item->pos_y = y;
	if (is_spawn(map->map[y][x]))
	{
		temp = doublelst_new(item);
		if (!temp)
			return (1);
		doublelst_addback(&map->spawn, temp);
	}
	return (0);
}

/*validates the map data to ensure map is closed*/
int	checking(t_map *map, size_t *map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (within_map(map->map[y][x]) && !(x && is_map(map->map[y][x - 1])
			&& map->map[y][x + 1] && is_map(map->map[y][x + 1])
			&& y && map_len[y - 1] >= x + 1 && is_map(map->map[y - 1][x - 1])
			&& is_map(map->map[y - 1][x]) && is_map(map->map[y - 1][x + 1])
			&& map->map[y + 1] && map_len[y + 1] >= x
			&& is_map(map->map[y + 1][x - 1])
			&& is_map(map->map[y + 1][x]) && is_map(map->map[y + 1][x + 1])))
				exit(write_error("error: map:\nMap is not closed\n"));
			if (is_spawn(map->map[y][x]))
				if (add_item(map, x, y))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*calculates the length of the complete map*/
int	cpl_map_len(char **map, size_t **map_len)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(is_map(map[y][x]) || map[y][x] == 32 || map[y][x] == '\n'))
				exit(write_error("error: map:\nBad map element\n"));
			x++;
		}
		(*map_len)[y] = x;
		y++;
	}
	return (0);
}

/*performs various checks to validate the map,
including checking for map closure, presence of spawn points*/
int	check_cub(t_map *map)
{
	size_t	*map_len;

	map_len = malloc(sizeof(size_t) * map->map_len);
	if (!map_len)
		exit(write_error("error: map:\nNo map found\n"));
	if (cpl_map_len(map->map, &map_len))
	{
		free(map_len);
		return (1);
	}
	if (checking(map, map_len))
	{
		free(map_len);
		return (1);
	}
	if (!map->spawn)
	{
		free(map_len);
		exit(write_error("error: map:\nNo place to spawn\n"));
	}
	free(map_len);
	return (0);
}
