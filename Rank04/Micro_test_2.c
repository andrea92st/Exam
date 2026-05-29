#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void err(char *str)
{
	while(*str)
		write(2, str++, 1);
}

int cd(char **argv, int i)
{
	if(i != 2)
		return err("error: cd: bad arguments\n"), 1;
	if(chdir(argv[1]) < 0)
		return err("error: cd: cannot change directory to"), err(argv[1]), err("\n"), 1;
	return 0; 
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if(has_pipe && (dup2(fd[end], end) == 1 || close (fd[0]) == -1 || close (fd[1]) == -1))
		err("error: fatal\n"), exit(1);
}

int main(int ac, char **av, char **envp)
{
	int i = 0;
	int status = 0;
	while(av[i])
	{
		av += i + 1;
		i = 0;
		while(av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i)
			status = 0; //exec
	}
	return status;
}