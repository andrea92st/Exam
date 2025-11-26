#include <stdlib.h>
#include <stdio.h>

int is_safe(int *line, int cur_col, int cur_row)
{
    int prev_col = 0;
    while (prev_col < cur_col)
    {
        int prev_row = line[prev_col]; 
        if(cur_row == prev_row
         || cur_col - cur_row == prev_col - prev_row
         || cur_col + cur_row == prev_col + prev_row)
                return(0);
        prev_col++;
    }        
        return(1);
    }
void solve(int *line, int col, int max)
{
    int j = 0;
    if(col == max)
    {
        while(j < max)
        {
            if(j > 0)
                fprintf(stdout, " ");
            fprintf(stdout, "%d", line[j]);
            j++;
        }
        fprintf(stdout, "\n");
        return ;
    }
    int row = 0;
    while(row < max)
    {
        if(is_safe(line, col, row))
        {
            line[col] = row;
            solve(line, col + 1, max);
        }
        row++;
    }
}

int main(int ac, char **av)
{
    if(ac != 2)
        return(0);
    int num = atoi(av[1]);
    if(num == 2 || num == 3)
        return(1);
    int *line = malloc (sizeof(int) * num);
	if (!line)
        return(1);
    solve(line, 0, num);
    free(line);
    return (0);
}
