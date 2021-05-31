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
    fd1 = open("a.txt", O_RDWR | O_APPEND);
    fd2 = open("a.txt", O_RDWR | O_APPEND);

    if((fd1 == -1) || (fd2 == -1))
    {
        perror("open failed...\n");
        _exit(-1);
    }
        
    // 写文件
    ret = write(fd1, "ab", 2);
    if(ret < 0)
    {
        perror("write failed...\n");
        _exit(-1);
    }
    ret = write(fd2, "cd", 2);
    if(ret < 0)
    {
        perror("write failed...\n");
        _exit(-1);
    }

    // lseek(fd, 0, SEEK_SET);    // 移动文件指针

    // 读文件
    // memset(readbuf, 0, sizeof(readbuf));

    // ret = read(fd1, readbuf, 10);
    // if(ret < 0)
    // {
    //     perror("read failed...\n");
    // }
    // else
    // {
    //     printf("read len: %d\n", ret);
    //     printf("read content: %s\n", readbuf);
    // }

    // memset(readbuf, 0, sizeof(readbuf));

    // ret = read(fd2, readbuf, 10);
    // if(ret < 0)
    // {
    //     perror("read failed...\n");
    // }
    // else
    // {
    //     printf("read len: %d\n", ret);
    //     printf("read content: %s\n", readbuf);
    // }

    close(fd1);
    close(fd2);

    return 0;
}
