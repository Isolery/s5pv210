#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = 0;
    int ret = 0;
    char writebuf[20] = "I Love Gaoman";
    char readbuf[20] = {0};

    // 打开文件
    fd = open("a.txt", O_RDWR | O_CREAT | O_EXCL, 0666);
    if(fd == -1)
    {
        perror("open failed...\n");
        _exit(-1);
    }
        
    // 写文件
    ret = write(fd, writebuf, strlen(writebuf));
    if(ret < 0)
    {
        perror("write failed...\n");
        _exit(-1);
    }

    lseek(fd, 0, SEEK_SET);    // 移动文件指针

    // 读文件
    ret = read(fd, readbuf, 10);
    if(ret < 0)
    {
        perror("read failed...\n");
    }
    else
    {
        printf("read len: %d\n", ret);
        printf("read content: %s\n", readbuf);
    }

    close(fd);

    return 0;
}
