#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_swap(char *a, char *b)
{
    char    c;

    c = *a;
    *a = *b;
    *b = c;
}

void    str_sort(char *str)
{
    int    j;

    for(int i = 0; str[i]; i++)
    {
        j = i;
        while (j > 0 && str[j] < str[j - 1])
        {
            ft_swap(str + j, str + j - 1);
            j--;
        }
    }
}

int    ft_strlen(char *str)
{
    int    len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int    next_perm(char *str)
{
    int    len = ft_strlen(str);
    int    i = len;
    int    min;

    while (i > 0 && str[i - 1] > str[i])
        i--;
    if (i == 0)
        return (0);
    min = i;
    for(int j = i + 1; j < len; j++)
        if (str[i - 1] < str[j] && str[j] < str[min])
            min = j;
    ft_swap(str + i - 1, str + min);
    str_sort(str + i);
    return (1);
}

int    main(int argc, char **argv)
{
    char    *str;

    if (argc == 2)
    {
        str = argv[1];
        str_sort(str);
        puts(str);
        while (next_perm(str))
            puts(str);
    }