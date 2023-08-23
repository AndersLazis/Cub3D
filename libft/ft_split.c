/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:27:47 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 23:42:49 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	words_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char const	*find_begin(char const *s, char c, unsigned int str_num)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			if (str_num)
				str_num--;
			else
				return (&s[i]);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (&s[i]);
}

static char	*trim_string(char const *s, char c, unsigned int str_num)
{
	char const	*begin;
	int			len;

	begin = find_begin(s, c, str_num);
	len = 0;
	while (begin[len] && begin[len] != c)
		len++;
	return (ft_substr(begin, 0, len));
}

static void	ft_free(char **arr, int to_delete)
{
	int	i;

	i = 0;
	while (i < to_delete)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	char			*tmp;
	unsigned int	i;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (words_counter(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words_counter(s, c))
	{
		tmp = trim_string(s, c, i);
		if (!tmp)
			ft_free(arr, i);
		arr[i++] = tmp;
	}
	arr[i] = NULL;
	return (arr);
}

// int main () {

// 	int i = 0;
// 	char * str = "abcdefcghcijk";
// 	char **ptr = ft_split(str, 'c');
// 	ptr = ft_split(str, 'c');
// 	while (ptr[i])
// 	{
// 		printf("%s\n", ptr[i]);
// 		i++;
// 	}
// }