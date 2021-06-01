#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t tNow = -1;

    time(&tNow);
    if(tNow < 0)
    {
        perror("time");
        return -1;
    }

    printf("time: %ld\n", tNow);

    printf("ctime: %s\n", ctime(&tNow));
}
