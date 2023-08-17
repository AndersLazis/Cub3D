/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:35 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:34:35 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_numbers(long number)
{
	int	counter;

	counter = 0;
	while (number > 0)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

static char	*ft_helper_swap(int i, int j, char *str)
{
	int	temp;

	while (i >= j + 1)
	{
		temp = str[i - 1];
		str[i - 1] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

static char	*ft_numtostring(long nb, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nb < 0)
	{
		str[i] = '-';
		i = 1;
		j = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i++] = (nb % 10 + '0');
		nb /= 10;
	}
	ft_helper_swap(i, j, str);
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		counter;
	long	number;

	counter = 0;
	number = nb;
	if (number <= 0)
	{
		counter++;
		number *= -1;
	}
	counter += count_numbers(number);
	str = malloc(counter + 1);
	if (!str)
		return (NULL);
	str[counter] = 0;
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (ft_numtostring(nb, str));
}

/*
int main(void)
{
	int nb = -880;
	printf("%s", ft_itoa(nb));
}
*/
