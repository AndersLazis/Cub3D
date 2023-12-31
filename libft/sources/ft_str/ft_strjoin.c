/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:11:36 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/05 08:30:49 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_merge(const char *s1, const char *s2)
{
	char	*merge;
	int		i;
	int		j;

	i = 0;
	j = 0;
	merge = malloc((sizeof(char) * (ft_strlen(s1)+ ft_strlen(s2) + 1)));
	if (!merge)
		return (NULL);
	while (s1[i])
	{
		merge[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		merge[j] = s2[i];
		j++;
		i++;
	}
	merge[j] = '\0';
	return (merge);
}

char	*ft_strjoin(char *s1, char *s2)
{
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	return (ft_merge(s1, s2));
}
