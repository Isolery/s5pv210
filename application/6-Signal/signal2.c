#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void func(int sig)
{
    if(sig == SIGALRM)
    {
        printf("alarm happened\n");
    }
}

int main(void)
{
    unsigned int ret = 0;
    struct sigaction act;

    act.sa_handler = func;

    //signal(SIGALRM, func);
    sigaction(SIGALRM, &act, NULL);

    ret = alarm(3);

    printf ("ret = %d\n", ret);

    while(1);

    return 0;
}