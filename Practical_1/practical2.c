
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[1024];
    int bytes;

    source = open("source.txt", O_RDONLY);

    if(source < 0)
    {
        printf("Source file not found.\n");
        return 1;
    }

    destination = open("destination.txt",
                       O_WRONLY | O_CREAT | O_TRUNC,
                       0644);

    while((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytes);
    }

    close(source);
    close(destination);

    printf("File Copied Successfully.\n");

    return 0;
}
