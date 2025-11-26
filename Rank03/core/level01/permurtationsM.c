#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s)
{
    int i=0;
    while (s[i])
        i++;
    return i;
}

void ft_swap(char *a, char *b)
{
    char tmp=*a;
    *a=*b;
    *b=tmp;
}

void bubble_sort(char *s, int len)
{
    for (int i=0;i<len-1;i++)
        for (int j=0;j<len-i-1;j++)
            if (s[j]>s[j+1])
                ft_swap(&s[j], &s[j+1]);
}

void backtrack(char *s, int len, char *perm, int *used, int pos)
{
    if (pos==len)
    {
        write(1, perm, len);
        write(1, "\n", 1);
        return ;
    }
    for (int i=0;i<len;i++)
    {
        if (used[i])
            continue ;
        used[i]=1;
        perm[pos]=s[i];
        backtrack(s, len, perm, used, pos+1);
        used[i]=0;
    }
}

int main(int ac, char **av)
{
    if (ac != 2 || !av[1])
        return (1);
    char *s = av[1];
    int len = ft_strlen(s);
    bubble_sort(s, len);
    char *perm=(char*)malloc(len+1);
    if (!perm)
        return (1);
    int *used=(int*)calloc(len, sizeof(int));
    if (!used)
        return (free(perm), 1);
    backtrack(s, len, perm, used, 0);
    free(perm);
    free(used);
    return (0);
}