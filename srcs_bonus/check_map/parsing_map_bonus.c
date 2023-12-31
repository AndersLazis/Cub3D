/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:02:05 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 09:33:43 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

/*goes through the input string until it finds '.'
 * checks if file extension ends in ".cub"*/
int	extension_cub(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i && str[i] != '.')
		i--;
	if (!i || ft_strncmp(".cub", &str[i], 4))
		exit(write_error("error: map:\nmap file must end in [.cub]\n"));
	return (0);
}

/*confirms that the required texture paths
 * ("NO", "EA", etc.) and color elements ("F", "C") are correctly specified*/
int	all_face(t_files *files)
{
	if (!files->f1 || !files->f2 || !files->f3
		|| !files->f4 || !files->f5 || !files->f6)
		exit(write_error("error: map file:\nmissing information\n"));
	return (0);
}

/*main function responsible for parsing the data
 * necessary to create the entire map*/
int	parse_map(t_map *map, t_files *files, char **argv)
{
	char	**tab;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(write_error("error: map:\nunable to open map file\n"));
	if (get_cub(fd, &tab))
	{
		ft_free(files->north, files->south, files->west, files->east);
		return (ft_free(files->c, files->f, files, 0));
	}
	close(fd);
	if (element_map(files, tab))
		return (free_tab(tab, 1));
	if (all_face(files))
		return (free_tab(tab, 1));
	if (take_cub(files, map, tab))
		return (free_tab(tab, 1));
	if (check_cub(map))
	{
		ft_free(files->north, files->south, files->west, files->east);
		ft_free(files->c, files->f, files, 0);
		return (free_tab(tab, 1));
	}
	return (free_tab(tab, 0));
}

int	file_convert(t_data *data, t_map *map, t_files *files)
{
	init_xpm(data, 1, files->north);
	init_xpm(data, 2, files->south);
	init_xpm(data, 3, files->west);
	init_xpm(data, 4, files->east);
	ft_free(files->north, files->south, files->west, files->east);
	init_xpm(data, 5, "./resources/door-02.xpm");
	init_xpm(data, 6, "./resources/object_01-1.xpm");
	init_xpm(data, 7, "./resources/object_02.xpm");
	init_xpm(data, 8, "./resources/object_03-1.xpm");
	init_xpm(data, 9, "./resources/object_04.xpm");
	init_xpm(data, 10, "./resources/object_05-1.xpm");
	init_xpm(data, 11, "./resources/object_06.xpm");
	init_xpm(data, 12, "./resources/object_01-1.xpm");
	init_xpm(data, 13, "./resources/door_new_01.xpm");
	init_xpm(data, 14, "./resources/door_new_01.xpm");
	init_xpm(data, 15, "./resources/door_new_01.xpm");
	init_xpm(data, 16, "./resources/door_new_01.xpm");
	if (convert_color(&map->f, files->f) || convert_color(&map->c, files->c))
		exit(write_error("error: map:\ncolor code error\n"));
	ft_free(files->c, files->f, files, 0);
	return (0);
}

/*higher-level function responsible for the parsing and data conversion*/
int	parsing_map(t_data *data, t_map *map, char **argv)
{
	t_files	*files;

	files = malloc(sizeof(t_files));
	if (!files)
		return (1);
	if (extension_cub(argv[1]))
		return (ft_free(files, 0, 0, 0));
	init_struct(files, map);
	if (parse_map(map, files, argv))
		return (1);
	if (file_convert(data, map, files))
		return (1);
	return (0);
}
