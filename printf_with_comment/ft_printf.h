/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:52:54 by rabderus          #+#    #+#             */
/*   Updated: 2021/12/02 21:47:46 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int ft_printf(const char *spec, ...);
int ft_convert(unsigned long pxX, char word, int num_S);
int	ft_putcharline(char *str);
int ft_star(unsigned long str);
int	ft_putchar_fd(int c);
int	ft_putnbr_fd(int s, int schet);
int	ft_putnbrplus_fd(unsigned int u, int schet);

#endif
