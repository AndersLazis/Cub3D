/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_util02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:39:00 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 09:26:33 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	is_map(char c)
{
	if (c == '1' || is_spawn(c) || within_map(c))
		return (1);
	return (0);
}

void	ft_tab_len(t_files *files, char **tab)
{
	size_t	i;

	i = files->map_begin;
	while (tab[i])
		i++;
	files->tab_len = i - files->map_begin;
}

int	is_map_beginning(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '1')
		return (1);
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '1' )
		&& (str[i] != '\0' && str[i] != '\n'))
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}
