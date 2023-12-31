/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:18:22 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 09:33:25 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

/*determines the type of elements encountered while parsing the map file*/
int	element_type(char *str, size_t i)
{
	if (!ft_strncmp("NO ", &str[i], 3))
		return (1);
	else if (!ft_strncmp("SO ", &str[i], 3))
		return (2);
	else if (!ft_strncmp("WE ", &str[i], 3))
		return (3);
	else if (!ft_strncmp("EA ", &str[i], 3))
		return (4);
	else if (!ft_strncmp("F ", &str[i], 2))
		return (5);
	else if (!ft_strncmp("C ", &str[i], 2))
		return (6);
	else if (is_map_beginning(str))
		return (7);
	else
		return (0);
}

/*stores data associated with different directions in the map file*/
int	face_cpl(t_files *files, char *str, size_t start, int face)
{
	size_t	end;

	end = start;
	while (str[end] && str[end] != 0)
		end++;
	if (face == 1 && ++files->f1)
		files->north = ft_substr(str, start, end - start);
	else if (face == 2 && ++files->f2)
		files->south = ft_substr(str, start, end - start);
	else if (face == 3 && ++files->f3)
		files->west = ft_substr(str, start, end - start);
	else if (face == 4 && ++files->f4)
		files->east = ft_substr(str, start, end - start);
	else if (face == 5 && ++files->f5)
		files->f = ft_substr(str, start, end - start);
	else if (face == 6 && ++files->f6)
		files->c = ft_substr(str, start, end - start);
	if ((face == 1 && !files->north) || (face == 2 && !files->south)
		|| (face == 3 && !files->west) || (face == 4 && !files->east)
		|| (face == 5 && !files->f) || (face == 6 && !files->c))
		exit(write_error("error: map:\nerror with directions\n"));
	return (0);
}

/*ensures that the correct elements are recognized
 * their associated data is extracted
 * and the t_files structure is appropriately updated*/
int	face_map(t_files *files, char *str, size_t i)
{
	int	face;

	i = 0;
	while (str[i] && (str[i] == 32 || str[i] == '\n'))
		i++;
	if (!str[i])
		return (0);
	face = element_type(str, i);
	if (face == 0)
		exit(write_error("error: map:\nfound unrecognized element\n"));
	else if (face == 7)
		return (2);
	while (str[i] && str[i] != 32)
		i++;
	while (str[i] && str[i] == 32)
		i++;
	if (face_cpl(files, str, i, face))
		return (1);
	while (str[i])
		i++;
	return (0);
}

/*iterates through each line of the map section
 * parsing and storing the data for the elements found in each line
 * error handling ensures that any failure during parsing
 * results in the deallocation of memory
 * and a return of 1 to indicate the error*/
int	element_map(t_files *files, char **tab)
{
	size_t	i;
	size_t	j;
	int		ret;

	i = 0;
	j = 0;
	while (tab[i])
	{
		ret = face_map(files, tab[i], j);
		if (ret == 1)
		{
			ft_free(files->north, files->south, files->west, files->east);
			ft_free(files->c, files->f, files, 0);
			return (1);
		}
		else if (ret == 2)
		{
			files->map_begin = i;
			return (0);
		}
		i++;
	}
	return (0);
}
