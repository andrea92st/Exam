#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *str;
char perm[100];
int used[100];
int len;

void ft_swap(char *a, char *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void str_sort(char *s)
{
	int j;

	for(int i = 0; str[i]; i++)
	{
		j = i;
		while(j > 0 && str[j] < str[j - 1])
		{
			ft_swap(s + j, s + j - 1);
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
		return ;
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
	str_sort(str);
	backtrack(0);
	return(0);
}
