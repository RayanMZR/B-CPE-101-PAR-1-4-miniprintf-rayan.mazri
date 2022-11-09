/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** loop && name flag
*/

#include "include/my.h"
#include <stdarg.h>

int pointer_flag(char c)
{
    char buffer[256] = "disc";
    for (int i = 0; buffer[i] != '\0'; i++)
        if (c == buffer[i])
            return i;
    return 84;
}

void find_flag(void (**flag)(), const char *str, int i, va_list lst)
{
    flag[pointer_flag(str[i])](va_arg(lst, int));
}

int loop_flag(void (**flag)(), const char *str, va_list lst)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '\0')
            return -1;
        if (str[i] == '%' && str[i + 1] == '%') {
            i += 2;
            my_putchar('%');
        }
        if (str[i] == '%') {
            i++;
            find_flag(flag, str, i, lst);
        } else
            my_putchar(str[i]);
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list lst;
    void (*flag[4])();

    flag[0] = &nbr;
    flag[1] = &nbr;
    flag[2] = &string;
    flag[3] = &character;

    va_start(lst, format);
    loop_flag(flag, format, lst);
    va_end(lst);
    return 0;
}
