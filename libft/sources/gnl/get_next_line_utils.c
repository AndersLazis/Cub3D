/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:23:51 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/06 09:08:44 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0x0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr2(const char *c, int i)
{
	int	j;

	j = 0;
	if (!c)
		return (NULL);
	if (i == '\0')
		return ((char *)&c[ft_strlen(c)]);
	while (c[j] != '\0')
	{
		if (c[j] == (char) i)
			return ((char *)&c[j]);
		j++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*c;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !buffer)
		return (NULL);
	c = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(buffer)) + 1));
	if (c == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str1)
		while (str1[++i] != '\0')
			c[i] = str1[i];
	while (buffer[j] != '\0')
		c[i++] = buffer[j++];
	c[ft_strlen(str1) + ft_strlen(buffer)] = '\0';
	free(str1);
	return (c);
}

char	*ft_line_get(char *str1)
{
	int		i;
	char	*s;

	i = 0;
	if (!str1[i])
		return (NULL);
	while (str1[i] && str1[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str1[i] && str1[i] != '\n')
	{
		s[i] = str1[i];
		i++;
	}
	if (str1[i] == '\n')
	{
		s[i] = str1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_line_new(char *str1)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str1[i] && str1[i] != '\n')
		i++;
	if (!str1[i])
	{
		free(str1);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(str1) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str1[i])
		s[j++] = str1[i++];
	s[j] = '\0';
	free(str1);
	return (s);
}
