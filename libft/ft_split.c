/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:33:46 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:33:46 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countparts(char const *s, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == sep)
			i++;
		if (s[i] != sep && s[i] != '\0')
			count++;
		while (s[i] != sep && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_mallocwords(char const *s, char sep)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] != sep && s[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (s[len] != sep && s[len] != '\0')
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**strs;
	int		j;

	j = -1;
	wordcount = ft_countparts(s, c);
	strs = ft_calloc((wordcount + 1) * sizeof(char *), 1);
	if (!strs)
		return (NULL);
	while (++j < wordcount)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		strs[j] = ft_mallocwords(s, c);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		while (*s != c && *s != '\0')
			s++;
	}
	return (strs);
}

/*
int main(void)
{
	int i;
	char test[] = " lem  ium dor   sit at, cur  adg elit. Sed non rius. Sse   ";
	char sep = ' ';

	char **test123;
	test123 = ft_split(test, sep);
	i = 0;
	while(i < 12)
	{
	printf("%s\n", test123[i]);
	i++;
	}
}
*/
