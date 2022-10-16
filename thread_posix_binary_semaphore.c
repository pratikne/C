//https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/
//Threads can use to synchronize their actions: mutexes and condition variables
//Mutex is a locking mechanism
//Semaphore is signaling mechanism

//Below is the implementation of binary semaphore which acts like mutex

#include <pthread.h> //IMP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h> //IMP

pthread_t tid[2];
int counter;
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
sem_t sema;

void* trythis(void* arg)
{
    //pthread_mutex_lock(&lock);
    sem_wait(&sema);
    int* t = (int*)arg;
    unsigned long i = 0;
    counter += 1;
    printf("\nThread [%d] Job %d has started\n", *t, counter);

    for (i = 0; i < (0xFFFFFFFF); i++)
        ;

    printf("\nThread [%d] Job %d has finished\n", *t, counter);

    //pthread_mutex_unlock(&lock);
    sem_post(&sema);

    return NULL;
}

int main(void)
{
    int i = 0;
    int error;

    /**if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }**/
    // int sem_init(sem_t *sem, int pshared, unsigned int value)
    // pshared if 0 -> Threads, Non 0 -> process
    // Unnamed semaphore
    sem_init(&sema,0,1);

    while (i < 2)
    {
        error = pthread_create(&(tid[i]),
                               NULL,
                               trythis, (void*)&tid[i]);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    //pthread_mutex_destroy(&lock);
    sem_destroy(&sema);

    return 0;
}