/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:30:49 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/09 13:17:47 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	write_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 12))
		return (1);
	return (0);
}

int	is_printable(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]) && (str[i] < 32 || str[i] > 126))
		{
			return (1);
		}
	}
	return (0);
}

int	is_spawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	within_map(char c)
{
	if (c == '0' || is_spawn(c))
		return (1);
	return (0);
}
