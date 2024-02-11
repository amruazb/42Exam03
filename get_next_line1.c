#include "so_long.h"

char *get_next_line(int fd)
{
    int index = 0;
    int bytes;
    char *buffer;
    char *new_buffer;
   
   buffer = malloc(BUFFER_SIZE + 1);
    if ((fd < 0) || (BUFFER_SIZE <= 0) || (buffer == NULL))
        return NULL;
    while ((bytes = read(fd, &buffer[index], 1)) > 0)
    {
        if (buffer[index] == '\n')
        {
            buffer[index + 1] = '\0';  // Null-terminate the string
            return buffer;
        }
        index++;
        if (index == BUFFER_SIZE)
        {
            new_buffer = realloc(buffer, 2 * BUFFER_SIZE + 1);
            if (new_buffer == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
    }
    if ((bytes <= 0) && (index == 0))
    {
        free(buffer);
        return NULL;
    }
    buffer[index] = '\0';  // Null-terminate the string
    return buffer;
}

int main()
{
    int fd = open("so_long.c", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    return 0;
}

