#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int ac, char **av)
{
	if(!av[1] || ac != 2)
	{
		perror("Error :");
		return (1);
	}
	int i = 0;
	char *s = av[1];
	int len = strlen(s);
	char c;
	ssize_t r = read(0, &c, 1);
	if(r < 0)
	{
		perror("Error :");
		return (1);
	}
	while (r == 1)
	{
		if(c == s[i])
		{
			i++;
			if(i == len)
			{
				for(int j = 0; j < len; j++)
					printf("*");
				i = 0;
			}
		}
		else
		{
			if(i > 0)
			{
				printf("%.*s", i, s);
				i = 0;
				if(c == s[i])
					i = 1;
				else
					printf("%c", c);
			}
			else
				printf("%c", c);
		}
		r = read(0, &c, 1);
		if(r < 0)
		{
			perror("Error :");
			return (1);
		}
	}
}