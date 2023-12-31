/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:24:28 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/30 09:33:05 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isneg(int *n, int *neg, int *temp)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*neg = -1;
		*temp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*neg = -1;
		*n = *n * -1;
		*temp = 0;
	}
	else if (*n > 0)
	{
		*neg = 1;
		*temp = 0;
	}
	else if (*n == 0)
	{
		*n = 0;
	}
}

static int	ft_itoa_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static void	ft_itoa_write(char *str, int len, int n, int temp)
{
	while (n > 9)
	{
		str[len--] = (n % 10) + '0' + temp;
		n = n / 10;
		temp = 0;
	}
	str[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int		neg;
	int		temp;
	int		len;
	char	*str;

	ft_isneg(&n, &neg, &temp);
	len = ft_itoa_len(n);
	if (neg == -1)
	{
		str = malloc((len + 2) * sizeof(char));
		if (!str)
			return (0);
		len++;
		str[0] = '-';
	}
	else
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	str[len--] = '\0';
	ft_itoa_write(str, len, n, temp);
	return (str);
}
