#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
}

int main()
{
    if(signal(SIGINT, handle_sigint)== SIG_ERR)
        printf("SIG Error");
    while (1)
    {
        printf("Hi ");
        sleep(1);
    }
    return 0;
}

