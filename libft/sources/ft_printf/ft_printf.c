/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:56:36 by tstrassb          #+#    #+#             */
/*   Updated: 2023/01/02 08:22:47 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		lenght;
	int		count;
	va_list	arg;

	count = 0;
	lenght = 0;
	va_start(arg, format);
	if (ft_strchr((char *)format, '%') == 0)
	{
		ft_putstr_fd((char *)format, 1);
		return (ft_strlen(format));
	}
	while (format[count])
	{
		if (format[count] != '%')
			lenght += write(1, &format[count], 1);
		else
		{
			lenght += (ft_choose_convers(arg, format[count + 1]));
			count++;
		}
		count++;
	}
	va_end(arg);
	return (lenght);
}
