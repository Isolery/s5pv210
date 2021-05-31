#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd1, fd2;
    int ret = 0;
    char writebuf[20] = "I Love Gaoman";
    char readbuf[20] = {0};

    // 打开文件
    fd1 = open("a.txt", O_RDWR);
    fd2 = open("a.txt", O_RDWR);

    if((fd1 == -1) || (fd2 == -1))
    {
        perror("open failed...\n");
        _exit(-1);
    }

    printf("fd1 = %d\n", fd1);

    close(1);

    // 复制文件描述符
    fd2 = dup2(fd1, 16);
        
    printf("fd2 = %d\n", fd2);

    close(fd1);
    close(fd2);

    return 0;
}
