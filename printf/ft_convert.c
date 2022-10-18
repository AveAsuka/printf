/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:39:51 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/03 18:01:52 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_count(unsigned long pxX, int num_S)
{
	int	mem_digit;
	int	ost;

	ost = 1;
	mem_digit = 0;
	while (pxX != 0)
	{
		ost = pxX % num_S;
		pxX /= num_S;
		mem_digit++;
	}
	return (mem_digit);
}

static void	write_16(char *sim, int counter)
{
	counter--;
	while (counter >= 0)
	{
		write (1, &sim[counter], 1);
		counter--;
	}
}

static char	get_simbol(int ost, char word)
{	
	char	a;

	if (ost >= 10)
		a = ost - 10 + word;
	else
		a = ost + '0';
	return (a);
}

int	ft_convert(unsigned long pxX, char word, int num_S)
{
	int		ost;
	char	*sim;
	int		counter;

	if (pxX == 0)
		return (write(1, "0", 1));
	sim = (char *)malloc(sizeof(char) * convert_count(pxX, num_S) + 1);
	counter = 0;
	while (pxX != 0)
	{
		ost = pxX % num_S;
		pxX /= num_S;
		sim[counter] = get_simbol(ost, word);
		counter++;
	}
	sim[counter] = '\0';
	write_16(sim, counter);
	free(sim);
	return (counter);
}
