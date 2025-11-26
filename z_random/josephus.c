#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int josephus(int bandits)
{
    int power = 1;
    while (power <= INT_MAX / 2 && 2 * power <= bandits)
        power *= 2;
    return (2 * (bandits - power) + 1);
}

int main(void)
{
    int bandits = 4;
    int survivant = josephus(bandits);
    printf("%d\n", survivant);
    return(0);
}