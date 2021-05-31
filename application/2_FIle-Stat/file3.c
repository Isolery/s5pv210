#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NAME "1.txt"

int main(void)
{
    int ret = 0;

    struct stat buf;

    memset(&buf, 0, sizeof(buf));

    ret = stat(NAME, &buf);

    if(ret < 0)
    {
        perror("stat");
        exit(-1);
    }

    // 判断文件权限

    int result = (buf.st_mode & S_IRUSR) ? 1 : 0;
    printf("result = %d\n", result);

    return 0;
}
