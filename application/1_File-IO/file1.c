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
    fd = open("a.txt", O_RDWR);
    if(fd == -1)
    {
        printf("open failed...\n");
    }
        
    // 写文件
    ret = write(fd, writebuf, strlen(writebuf));
    if(ret < 0)
    {
        printf("write failed...\n");
    }

    // 读文件
    ret = read(fd, readbuf, 10);
    if(ret < 0)
    {
        printf("read failed...\n");
    }
    else
    {
        printf("read len: %d\n", ret);
        printf("read content: %s\n", readbuf);
    }

    close(fd);

    return 0;
}
