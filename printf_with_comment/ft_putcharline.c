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
