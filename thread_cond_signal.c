// C program to implement cond(), signal()
// and wait() functions
// Threads can use to synchronize their actions: mutexes and condition variables
// Best case is of Producer-Consumer problem
// Refer : https://www.geeksforgeeks.org/condition-wait-signal-multi-threading/
// 
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
 
// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
 
// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
 
int done = 1;
 
// Thread function
void* foo(void* tid)
{
    int* t = (int*)tid;
 
    // acquire a lock
    pthread_mutex_lock(&lock);
    if (done == 1) {
 
        // let's wait on condition variable cond1
        done = 2;
        printf("Thread [%d] Waiting on condition variable cond1\n",*t);
        pthread_cond_wait(&cond1, &lock); 
        //Thread 1 waits after unlocking the mutex internally..so other thread who will recieve the signal can access the resource
        printf("Thread [%d] doing its job now\n",*t);
        sleep(2);
    }
    else {
 
        // Let's signal condition variable cond1
        printf("Thread [%d] doing its job now\n",*t);
        sleep(2);
        printf("Thread [%d] Signaling condition variable cond1\n",*t);
        pthread_cond_signal(&cond1);
    }
 
    // release lock
    pthread_mutex_unlock(&lock);
 
    printf("Returning thread [%d]\n",*t);
 
    return NULL;
}
//Objective here was to allow thread 2 to execute before thread 1

// Driver code
int main()
{
    pthread_t tid1, tid2;
 
    // Create thread 1
    pthread_create(&tid1, NULL, foo, (void*)&tid1);
 
    // sleep for 5 sec so that thread 1
    // would get a chance to run first
    sleep(5);
 
    // Create thread 2
    pthread_create(&tid2, NULL, foo, (void*)&tid2);
 
    // wait for the completion of thread 2
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}