#include "gnl.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;
	dest = malloc(ft_strlen(src) + 1);
	if(dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	static int buffer_pos = 0;
	static int buffer_read = 0;
	static char buffer[BUFFER_SIZE];

	int i = 0;
	char line[10000];
	if(fd < 0 || BUFFER_SIZE <= 0)
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read == 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1]== '\n')
			break;
	}
	if (i == 0)
        return NULL;
    line[i] = '\0';    
    return ft_strdup(line);
}






}