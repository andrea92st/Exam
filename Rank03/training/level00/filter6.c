#include <unistd.h>
#include <stdio.h>


int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}

int main(int ac, char **av)
{
	if(ac != 2 || !av[1])
	{
		perror("Error: ");
		return(1);
	}
	int i = 0;
	char c;
	char *s = av[1];
	int len = ft_strlen(s);
	ssize_t r = read(0, &c, 1);
	if(r <= 0)
	{
		perror("Error: ");
		return(1);
	}
	while(r == 1)
	{
		if(c == s[i])
		{
			i++;
			if(i == len)
			{
				i = 0;
				for(int j = 0; j < len; j++)
					printf("*");	
			}
		}
		else
		{
			if(i > 0)
			{
				printf("%.*s", i, s);
				i = 0;
				if(c == s[i])
					i++;
				else
					printf("%c", c);
			}
			else
				printf("%c", c);
		}
		r = read(0, &c, 1);
		if(r <= 0)
		{
			perror("Error: ");
			return(1);
		}
	}
}