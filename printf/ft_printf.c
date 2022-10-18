/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:03:53 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/03 18:08:23 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	which_spec(va_list ptr, int i)
{
	if (i == 'c')
		return (ft_putchar_fd(va_arg(ptr, int)));
	if (i == 'd' || i == 'i')
		return (ft_putnbr_fd(va_arg(ptr, int), 0));
	if (i == 'u')
		return (ft_putnbrplus_fd(va_arg(ptr, unsigned int), 0));
	if (i == 's')
		return (ft_putcharline(va_arg(ptr, char *)));
	if (i == 'p')
		return (ft_star(va_arg(ptr, unsigned long)));
	if (i == 'x')
		return (ft_convert(va_arg(ptr, unsigned int), 'a', 16));
	if (i == 'X')
		return (ft_convert(va_arg(ptr, unsigned int), 'A', 16));
	 if (i == '%')
		 return (write (1, "%", 1));
	return (write (1, "%", 1));
}

static int	analiz_spec(va_list ptr, const char *spec)
{
	int	i;
	int	flag;
	int	counter;

	i = 0;
	flag = 0;
	counter = 0;
	while (spec[i])
	{
		if (flag == 1)
		{
			counter += which_spec(ptr, spec[i]);
			flag = 0;
		}
		else
		{
			if (spec[i] == '%')
				flag = 1;
			else
				counter += write (1, &spec[i], 1);
		}
		i++;
	}
	return (counter);
}

int	ft_printf(const char *spec, ...)
{
	va_list	ptr;

	va_start(ptr, spec);
	return (analiz_spec(ptr, spec));
}
