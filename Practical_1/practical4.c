#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i;
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Parent PID : %d\n\n", getpid());

    for(i = 1; i <= 3; i++)
    {
        pid = fork();

        if(pid == 0)
        {
            printf("Child %d Created\n", i);
            printf("Child PID : %d\n", getpid());
            printf("Parent PID: %d\n\n", getppid());

            sleep(2);

            printf("Child %d Finished\n\n", i);

            exit(0);
        }
    }

    for(i = 1; i <= 3; i++)
    {
        wait(NULL);
    }

    printf("All Child Processes Completed using wait().\n");

    return 0;
}
