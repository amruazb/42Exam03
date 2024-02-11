#include "so_long.h"
//have an issue for buffer fixed on the get_next_line1.c
char *get_next_line(int fd)
{
    int index;
    int bytes;
    char *buffer;
    char character;

    if((fd < 0) || (BUFFER_SIZE <= 0))
        return (NULL);
    index = 0;
    bytes = read(fd, &character, 1);
    buffer = malloc(BUFFER_SIZE + 1);
    while(bytes > 0)
    {
        buffer[index++] = character;
        if (character == '\n')
            break ;
        bytes = read(fd, &character,1);
    }
    if((bytes <= 0) && (index == 0))
        return (free(buffer), NULL);
    buffer[index] = '\0';
    return (buffer);
}


int main()
{
    int fd;
   fd = open("so_long.c",O_RDONLY);
    char *line;

   while((line = get_next_line(fd)))
   {
    	printf("%s",line);
   	 free(line);
    }
}


