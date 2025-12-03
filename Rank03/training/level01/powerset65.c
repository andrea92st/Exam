#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
		mask >>= 1;
		i++;
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
			sum += (atoi(tab[i]));
		mask >>= 1;
		i++;
	}
	return(sum);
}
int main(int ac, char **av)
{
	int n = 0;
	int target = 0;
	unsigned int mask = 0;

	if(ac >= 2)
	{
		target = atoi(av[1]);
		n = ac - 2;
	}
	while(mask <= (1 << n) - 1)
	{
		if(sum_of_int(mask, av + 2)== target)
			print_nums(mask, av + 2);
		mask++;
	}
}
