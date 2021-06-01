#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = 0;

    pid = fork();

    if(pid == 0)
    {
        // 子进程
        printf("This is child process... pid = %d\n", getpid());
       
        execl("./hello", "hello", NULL);
    }

    if(pid > 0)
    {
        // 父进程
        printf("This is parent process... pid = %d\n", getpid());
    }

    if (pid < 0)
    {
        // fork失败
    }

    sleep(1);

    return 0;
}
