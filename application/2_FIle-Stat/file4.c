#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int ret = 0;

    ret = access("1.txt", F_OK);    // 检测文件是否存在
    if(ret < 0)
    {
        printf("file not exist...\n");
    }
    else
    {
        printf("file exist...\n");
    }

    ret = access("1.txt", R_OK);    // 检测文件是否可读
    if(ret < 0)
    {
        printf("file not read...\n");
    }
    else
    {
        printf("file can read...\n");
    }

    return 0;
}