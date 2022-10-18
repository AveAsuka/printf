#include "ft_printf.h"

// Вывод целого числа без знака в шестнадцетеричной систем счисления. 
// Причем для преобразования x используются символы abcdef, а для X - символы ABCDEF. 
// По умолчанию выводится число размером sizeof( int ), с правым выравниванием.

static int convert_count(unsigned long pxX, int num_S)
{
    int mem_digit;
    int ost;

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

// ???
static void write_16(char *sim, int counter) 
{
    counter--;
    while (counter >= 0) //?
    {
        write (1, &sim[counter], 1);
        counter--;
    }
}

// подаем некий инт, тип регистра, в какую систему счисления конвертируем
// нам нужно заврайтить уже сконвертированный символ и вернуть инт counter
int ft_convert(unsigned long pxX, char word, int num_S)
{
    int ost; // наш остаток, с которым шаманим, чтобы получить символ в 16
    char *sim; // преоброзованный символ, который надо врайтить
    int counter; // счетчик для ретерн

    if (pxX == 0)
        return(write (1, "0", 1));
    sim = (char *)malloc(sizeof(char) * convert_count(pxX, num_S) + 1);
    counter = 0;
    while (pxX != 0)
    {
        ost = pxX % num_S;
        pxX /= num_S;
        if (ost >= 10)
        {
            sim[counter] = ost - 10 + word;
            counter++;
        }
        else
        {
            sim[counter] = ost + '0';
            counter++;
        }
    }
    sim[counter]= '\0';  // ? непонятно что с нулем в конце делать
    write_16(sim, counter);
    free(sim);
    return (counter);
}