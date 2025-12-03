#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char *str;
char perm[100];
int used[100];
int len;

void ft_swap(char *a, char *b)
{
	int i = *a;
	*a = *b;
	*b = i;
}
void ft_sort(void)
{
	int j;
	for(int i = 0; str[i]; i++)
	{
		j = i;
		while(j > 0 && str[j] < str[j - 1])
		{
			ft_swap(str + j, str + j - 1);
			j--;
		}
	}
}
void backtrack(int pos)
{
	if(pos == len)
	{
		perm[len] = '\0';
		puts(perm);
		return;
	}
	for(int i = 0; i < len; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			perm[pos] = str[i];
			backtrack(pos + 1);
			used[i] = 0;
		}
	}
}
int main(int ac, char **av)
{
	if(ac != 2)
		return (1);
	str = av[1];
	while(str[len])
		len++;
	ft_sort();
	backtrack(0);
	return(0);
}
