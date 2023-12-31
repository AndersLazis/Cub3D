/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:06:43 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/27 13:41:32 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		begin;
	int		end;
	int		i;

	i = 0;
	begin = 0;
	if (s1 == 0 || set == 0)
		return (0);
	end = (int)ft_strlen(s1);
	while (s1[begin] && ft_checkset(s1[begin], set))
		begin++;
	while (end > begin && ft_checkset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (0);
	while (begin < end)
	{
		str[i] = s1[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}
