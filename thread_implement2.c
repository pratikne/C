// Thread implementation
// How to return from Thread

#include <pthread.h>
#include "tlpi_hdr.h"

static void* threadFunc(void* arg)
{
    char* s = (char*) arg;
    printf("%s", s);
    return (void*) strlen(s);
}

int main(int argc, char* argv[])
{
    pthread_t t1;
    pthread_attr_t attr;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    void* res;
    int s;

    s = pthread_attr_init(&attr); /* Assigns default attribute values */
    if (s != 0)
        printf("pthread_attr_init error");
    
    /**s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (s != 0)
        printf("pthread_attr_setdetachstate error");**/

    char* message = "Hello World";
    s = pthread_create(&t1, NULL, threadFunc, (void*)message);
    if (s != 0)
        printf("pthread_create error");

    printf("Message from main()\n");

    s = pthread_join(t1, &res);
    if (s != 0)
        printf("pthread_join error");

    printf("Thread returned %ld\n", (long*) res);
    exit(EXIT_SUCCESS);
}