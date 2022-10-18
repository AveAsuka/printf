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
