/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util01_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:41:33 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/29 16:21:53 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

static void	free_join(void *s1, void *s2, int i)
{
	if (i == 1 || i == 3)
		free(s1);
	else if (i == 2 || i == 3)
		free(s2);
}

char	*ft_free_join(char const *s1, char const *s2, int i)
{
	char	*dest;
	size_t	j;
	size_t	len_s1;
	size_t	len_dest;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	len_s1 = ft_strlen(s1);
	len_dest = len_s1 + ft_strlen(s2);
	dest = malloc(sizeof(*dest) * len_dest + 1);
	if (!dest)
		return (0);
	j = -1;
	while (s1[++j])
		dest[j] = s1[j];
	j = -1;
	while (s2[++j])
		dest[len_s1 + j] = s2[j];
	dest[len_s1 + j] = '\0';
	if (i)
		free_join((void *)s1, (void *)s2, i);
	return (dest);
}

int	free_tab(char **tab, int ret)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (ret);
}

int	ft_free(void *s1, void *s2, void *s3, void *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
	return (1);
}

void	init_struct(t_files *files, t_map *map)
{
	files->map_begin = 0;
	files->tab_len = 0;
	files->north = 0;
	files->east = 0;
	files->south = 0;
	files->west = 0;
	files->f = 0;
	files->f1 = 0;
	files->f2 = 0;
	files->f3 = 0;
	files->f4 = 0;
	files->f5 = 0;
	files->f6 = 0;
	map->spawn = 0;
	map->item = 0;
}
