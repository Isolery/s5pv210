#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
    time_t tNow = -1;
    struct tm tmNow;

    time(&tNow);

    if(tNow < 0)
    {
        perror("time");
        return -1;
    }
    printf("time: %ld\n", tNow);

    memset(&tmNow, 0, sizeof(tmNow));

    tmNow = gmtime(&tNow);
    printf("%d %d %d\n", tmNow.tm_year, tmNow.tm_mon, tmNow.tm_mday);

    return 0;
}
