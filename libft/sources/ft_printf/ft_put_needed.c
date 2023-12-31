/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_needed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:15:52 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/10 09:20:58 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	if (!c)
		return ;
	while (c[i])
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int i, int fd)
{
	if (i == INT_MIN)
		ft_putstr_fd("-2147483648", fd);
	else if (i < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(i * -1, fd);
	}
	else if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else if (i >= 0 && i <= 9)
		ft_putchar_fd(i + '0', fd);
} */

void	ft_unsignedputnbr_fd(unsigned int i, int fd)
{
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	if (i <= 9)
		ft_putnbr_fd(i + 0, fd);
}
