/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:56:41 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/30 09:26:25 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	read_cub(char **str, int fd)
{
	long	len;

	len = read(fd, *str, 10240);
	if (len == -1)
		return (1);
	(*str)[len] = 0;
	return (0);
}

/*reads the mapfile .cub and checks for errors
 *in the input file and prepares data in the file*/
int	get_cub(int fd, char ***tab)
{
	char	*s1;
	char	*str;

	s1 = malloc(10241);
	str = 0;
	if (read_cub(&s1, fd))
		exit(write_error("error: mapfile:\nread failed\n"));
	while (s1 && *s1)
	{
		if (is_printable(s1))
			exit(write_error("error: mapfile:\nbad element\n"));
		str = ft_free_join(str, s1, 1);
		if (!str || read_cub(&s1, fd))
		{
			exit(write_error("error: mapfile:\nread failed\n"));
		}
	}
	*tab = split01(str, '\n');
	if (!*tab && ft_free(s1, 0, 0, 0))
		exit(write_error("error: mapfile:\nmap empty\n"));
	free(s1);
	free(str);
	return (0);
}
