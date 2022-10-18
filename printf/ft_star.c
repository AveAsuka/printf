/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:09:48 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/03 18:09:58 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_star(unsigned long str)
{
	int	counter;

	if (!str)
	{
		write (1, "0x0", 3);
		return (3);
	}
	else
	{
		counter = write (1, "0x", 2);
		counter += ft_convert(str, 'a', 16);
	}
	return (counter);
}
