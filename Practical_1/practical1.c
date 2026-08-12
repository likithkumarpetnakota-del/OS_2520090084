// practical1.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char command[100];

    printf("Enter Linux Command: ");
    scanf("%s", command);

    pid_t pid = fork();

    if(pid < 0)
    {
        printf("Fork Failed\n");
    }

    else if(pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child PID : %d\n", getpid());

        execlp(command, command, NULL);

        printf("Invalid Command\n");
    }

    else
    {
        printf("\nParent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        wait(NULL);

        printf("\nChild Process Completed.\n");
    }

    return 0;
}
