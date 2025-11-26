#include <stdlib.h>
#include <stdio.h>

int    sum_of_int(unsigned int mask, char **tab)
{
    int    i;
    int    sum;

    i = 0;
    sum = 0;
    while (mask)
    {
        if ((mask & 1) == 1)
            sum += atoi(tab[i]);
        mask >>= 1;
        i++;
    }
    return (sum);
}

void    print_nums(unsigned int mask, char **tab)
{
    int    i;

    i = 0;
    while (mask)
    {
        if ((mask & 1) == 1)
        {
            printf("%d", atoi(tab[i]));
            if (mask >> 1)
                printf(" ");
        }
        mask >>= 1;
        i++;
    }
    printf("\n");
}

int    main(int argc, char **argv)
{
    int  n = 0;
    int  target = 0;
    unsigned int    mask = 0;

    if (argc >= 2)
    {
        n = argc - 2;
        target = atoi(argv[1]);
        mask = 0;
    }
    while (mask <= (1 << n) - 1)
    {
        if (sum_of_int(mask, argv + 2) == target)
            print_nums(mask, argv + 2);
        mask++;
    }
}
