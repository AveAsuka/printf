#include "ft_printf.h"

int ft_star(unsigned long str)
{
    int counter;

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
