#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

// тут опрделяем точно какой спецификатор, и в зависимости от этого, решаем
// что делать дальше
static int which_spec(va_list ptr, int i)
{
// %c печатает один символ типа char
    if (i == 'c')
        return (ft_putchar_fd(va_arg(ptr, int)));

// %i print an integer in base 10.
// %d Десятичное число целого типа со знаком
    if (i == 'd' || i == 'i')
        return (ft_putnbr_fd(va_arg(ptr, int), 0));

// %u Десятичное число целого типа без знака
    if (i == 'u')
        return (ft_putnbrplus_fd(va_arg(ptr, unsigned int), 0));

// %s выводит строку символов.
    if (i == 's')
        return (ft_putcharline(va_arg(ptr, char *)));

// %p Аргумент указателя void * выводится в шестнадцатеричном формате.
// или же выводит на экран значение указателя
    if (i == 'p')
        return (ft_star(va_arg(ptr, unsigned long)));

// %x Шестнадцатиричное целое число без знака (буквы нижнего регистра)
    if (i == 'x')
        return (ft_convert(va_arg(ptr, unsigned int), 'a', 16));

// %X Шестнадцатиричное целое число без знака (буквы верхнего регистра)
    if (i == 'X')
        return (ft_convert(va_arg(ptr, unsigned int), 'A', 16));

// %% выведите знак процента
     if (i == '%')
         return (write (1, "%", 1));
    
    return (write (1, "%", 1));
    //return 0;
}

//тут надо перебрать всю строчку ptr и при встрече 
//спецификатора перекидывать его на след. функцию
static int analiz_spec(va_list ptr, const char *spec)
{
    int i;
    int flag;
    int counter;

    i = 0;
    flag = 0;
    counter = 0;
// надо рассмотреть несколько сценариев, мы встречаем: а) '%',
// б) какой-то текст
    while (spec[i])
    {
        if (flag == 1)
        {
            counter += which_spec(ptr, spec[i]);
            flag = 0;
        }
        else
        {
            if (spec[i] == '%')
                flag = 1;
            else
            {
                write (1, &spec[i], 1);
                counter++;
            }
        }

        i++;
    }

    return (counter);
}

// Синтаксис: int printf (const char *format, ...);
// Аргументы: format – указатель на строку c описанием формата.

// Возвращаемое значение:
// При успешном завершении вывода возвращается количество выведенных символов.
// При ошибке возвращается отрицательное число.

// Функция printf выводит в стандартный поток вывода строку отформатированную  
// в соответствии с правилами, указанными в строке, на которую указывает аргумент format.
// Правила задаются набором трех типов директив:
// 1. Обычные символы (кроме '%' и '\'), которые выводятся без изменения;
// 2. Спецификаторы формата;
// 3. Специальные сиволы.

// "связываем" нашу строку spec с va_list-ом, чтобы было можно было
// "перебирать" что за ней
int ft_printf(const char *spec, ...)
{
    va_list ptr;

    va_start(ptr, spec);
    return(analiz_spec(ptr, spec));
}

// int main()
// {   
//     int test = 42;
// 	//PRINTF(("%p", &test));
//     //int *a = "D";
// 	//printf("%u\n", -);
//     //printf("%u\n", -0);
//     // printf("%d\n", 1234567891011);
//     // ft_printf("%d\n", 1234567891011);

//     printf("%d]\n", printf("%p", &test));
//     printf("%d]", ft_printf("%p", &test));
// //	ft_printf("%X\n", i);

//     return 0;
// }
