#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>

int main(void)
{
	// 读取鼠标
	int fd = 0;
	char buf[200];
    int ret = 0;
    fd_set myset;
    struct timeval tm;

	fd = open("/dev/input/mouse0", O_RDONLY | O_NONBLOCK);
	if (fd < 0)
	{
		perror("open:");
		return -1;
	}

    FD_ZERO(&myset);
    FD_SET(fd, &myset);
    FD_SET(0, &myset);

    tm.tv_sec = 5;
    tm.tv_usec = 0;

    ret = select(fd+1, &myset, NULL, NULL, &tm);

    if(ret < 0)
    {
        perror("select: ");
    }
    else if(ret == 0)
    {
        printf("timeout...\n");
    }
    else
    {
        // 有IO事件发生
        if(FD_ISSET(0, &myset))
        {
            // 处理键盘
            memset(buf, 0, sizeof(buf));
            read(0, buf, 5);
            printf("keyboard: %s\n", buf);
        }

        if(FD_ISSET(fd, &myset))
        {
            // 处理鼠标
            memset(buf, 0, sizeof(buf));
            read(fd, buf, 50);
            printf("mouse: %s\n", buf);
        }
    }
	
	return 0;
}
