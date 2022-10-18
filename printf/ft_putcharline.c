/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:08:52 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/03 18:08:55 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharline(char *str)
{
	int	s;

	s = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[s])
	{
		write(1, &str[s], 1);
		s++;
	}
	return (s);
}
