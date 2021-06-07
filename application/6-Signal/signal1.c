#include <stdio.h>
#include <signal.h>

void func(int sig)
{
    printf("func for signal %d\n", sig);
}

int main(void)
{   
    signal(SIGINT, func);

    printf("before while(1)\n");

    while(1);

    printf("after while(1)\n");

    return 0;
}
