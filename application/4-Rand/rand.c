#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i = 0;
    int val = 0;

    srand(time(NULL));

    for(i = 0; i < 10; i++)
    {
        val = rand();
        printf("%d\n", val%10);
    }

    return 0;
}
