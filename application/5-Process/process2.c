#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd = 0;
    pid_t pid = 0;

    pid = fork();

    if(pid == 0)
    {
        // 子进程
        fd = open("1.txt", O_RDWR | O_APPEND);

        printf("child process\n");
        write(fd, "world", 5);
        sleep(1);
    }

    if(pid > 0)
    {
        // 父进程
        fd = open("1.txt", O_RDWR | O_APPEND);

        printf("parent process\n");
        write(fd, "hello", 5);
        sleep(1);
    }

    if (pid < 0)
    {
        // fork失败
    }

    sleep(1);

    close(fd);

    return 0;
}
