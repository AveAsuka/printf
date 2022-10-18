// Выводит целое число 'n' в указанный файловый дескриптор 'fd'.
#include "ft_printf.h"

int	ft_putnbr_fd(int d, int schet)
{
	long D;

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
		schet += ft_putchar_fd(D + '0'); //? 

	return (schet);
}
