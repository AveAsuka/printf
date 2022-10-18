/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:09:05 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/03 18:09:23 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int d, int schet)
{
	long	D;

	D = (long)d;
	if (D < 0)
	{
		schet += ft_putchar_fd('-');
		D = -D;
	}
	if (D >= 10)
	{
		schet = ft_putnbr_fd(D / 10, schet);
		schet = ft_putnbr_fd(D % 10, schet);
	}
	else
		schet += ft_putchar_fd(D + '0');
	return (schet);
}
