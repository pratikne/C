
#include <pthread.h> //IMP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h> //IMP
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"
#define SEM_MUTEX_NAME "/sem-mutex"

pthread_t tid[2];
int counter;

sem_t *sem;

void *trythis(void *arg)
{
    // pthread_mutex_lock(&lock);
    int value;
    sem_getvalue(sem, &value);
    printf("\nSem value [%d] \n", value);
    sem_wait(sem);
    int *t = (int *)arg;
    unsigned long i = 0;
    counter += 1;
    printf("\nThread [%d] Job %d has started\n", *t, counter);

    for (i = 0; i < (0xFFFFFFFF); i++)
        ;

    printf("\nThread [%d] Job %d has finished\n", *t, counter);

    // pthread_mutex_unlock(&lock);
    sem_post(sem);

    return NULL;
}

int main(void)
{
    int flags, opt;
    mode_t perms;
    unsigned int value;

    /**
    flags |= O_CREAT;
    perms |= O_RDWR;
    value = 1 ;//One semaphore
    **/
    int error;
    int i = 0;

    sem = sem_open(SEM_MUTEX_NAME, IPC_CREATE , 0660, 1); //currentky giving error due to MINGW
    if(sem == SEM_FAILED){
        printf("Error");
        perror("sem_open");
        exit(0);
    }
    //int value;
    sem_getvalue(sem, &value);
    printf("\nSem value first [%d] \n", value);
    //sem_init(&sema, 0, 1);

    while (i < 2)
    {
        error = pthread_create(&(tid[i]),
                               NULL,
                               trythis, (void *)&tid[i]);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    sem_close(sem);

    return 0;
}