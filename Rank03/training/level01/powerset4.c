#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_nums(unsigned int mask, char **tab)
{
	int i = 0;
	while(mask)
	{
		if((mask & 1) == 1)
		{
			printf("%d", atoi(tab[i]));
			if(mask >> 1)
				printf(" ");
		}
		i++;
		mask >>= 1;
	}
	printf("\n");
}
int sum_of_int(unsigned int mask, char **tab)
{
	int i = 0;
	int sum = 0;
	while(mask)
	{
		if((mask & 1) == 1)
			sum += atoi(tab[i]);
		i++;
		mask >>= 1;
	}
	return (sum);
}
int main(int ac, char **av)
{
	int n = 0;
	int target = 0;
	unsigned int mask = 0;

	if(ac >= 2)
	{
		n = ac - 2;
		target = atoi(av[1]);
	}
	while(mask <= (1U << n) - 1)
	{
		if(sum_of_int(mask, av + 2) == target)
			print_nums(mask, av + 2);
		mask++;
	}
}
