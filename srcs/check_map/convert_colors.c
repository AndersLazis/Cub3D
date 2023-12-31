/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:11:39 by tstrassb          #+#    #+#             */
/*   Updated: 2023/08/29 15:34:49 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/*goes through the string of the color input*/
int	check_str_color(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && j <= 2)
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j > 2)
		return (1);
	return (0);
}

/*skips white spaces to look for the ',' in the color input*/
size_t	ft_lookup_comma(char *str, size_t start)
{
	size_t		end;
	size_t		check;
	static int	set;

	set = 2;
	end = start;
	while (str[end] && (!set || str[end] != ','))
	{
		if (str[end] == ',')
			set--;
		if (!ft_isspace(str[end]))
			check = ++end;
		else
			end++;
	}
	return (check);
}

/*splits the 3 color values and stores them in [tab]*/
char	**split_color(char *str)
{
	char	**tab;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	tab = malloc(sizeof(char *) * 4);
	while (i < 3)
	{
		start = end;
		while (str[start] && str[start] == 32)
			start++;
		if (str[start] == ',')
			start++;
		while (str[start] && str[start] == 32)
			start++;
		end = ft_lookup_comma(str, start);
		tab[i] = ft_substr(str, start, end - start);
		if (!tab[i++] && free_tab(tab, 1))
			return (0);
	}
	tab[i] = 0;
	return (tab);
}

/*converts RGB color components into a
 * single integer color value using bitwise operations*/
int	ft_rgb(int *color, unsigned int rgb[3], int i)
{
	if (rgb[i] > 255)
		return (1);
	*color += (rgb[i] << (((i + 2) - (i * 2)) * 8));
	return (0);
}

/*parses and converts RGB color values
 * from a string format to an integer format
 * It ensures that the input string is well-formatted,
 * converts the RGB components, and combines them into
 * a single integer color value for further use*/
int	convert_color(int *color, char *str)
{
	unsigned int	rgb[3];
	size_t			i;
	char			**tab;

	if (check_str_color(str))
		return (1);
	tab = split_color(str);
	if (tab == 0)
		exit(write_error("error: map:\nmalloc for color failed\n"));
	i = -1;
	while (tab[++i])
		rgb[i] = ft_atoi(tab[i]);
	i = 0;
	*color = 0;
	while (i < 3)
		if (ft_rgb(color, rgb, i++))
			return (ft_free(tab[0], tab[1], tab[2], tab));
	ft_free(tab[0], tab[1], tab[2], tab);
	return (0);
}
