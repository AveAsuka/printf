/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrplus_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:09:30 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/03 18:09:39 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrplus_fd(unsigned int u, int schet)
{
	if (u >= 10)
	{
		schet = ft_putnbrplus_fd(u / 10, schet);
		schet = ft_putnbrplus_fd(u % 10, schet);
	}
	else
		schet += ft_putchar_fd(u + '0');
	return (schet);
}
