// practical3.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        printf("\nChild Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());

        sleep(10);
    }

    else
    {
        printf("\nParent Process\n");
        printf("PID  : %d\n", getpid());

        wait(NULL);

        printf("Child Finished\n");
    }

    return 0;
}
