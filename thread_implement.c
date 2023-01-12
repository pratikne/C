/**https://www.geeksforgeeks.org/multithreading-c-2/
 * 
 */

/**#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
 
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp)
{
    sleep(5);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t thread_id;
    pthread_attr_t attr;
    printf("Before Thread\n");

    // int pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(*func)(void *), void *arg)
    pthread_create(&thread_id, NULL, myThreadFun, NULL);

    // int pthread_join(pthread_t t, void **res)
    // Blocks the calling thread until thread with thread_id passed is terminated
    pthread_join(thread_id, NULL);

    printf("After Thread\n");
    exit(0);
}**/

/**Below steps to compile this program (IMP)
 * gcc -o pthread_imp .\pthread_impl.c -lpthread

 .\pthread_imp.exe

Before Thread
Printing GeeksQuiz from Thread 
After Thread
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
// Let us create a global variable to change it in threads
int g = 0;
 
// The function to be executed by all threads
void* myThreadFun(void* vargp)
{
    // Store the value argument passed to this thread
    int* myid = (int *) vargp; // pthread_t* tid = (pthread_t*) vargp;
 
    // Let us create a static variable to observe its changes
    static int s = 0;
 
    // Change static and global variables
    ++s; ++g;
 
    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}
 
int main(int argc, char* argv[])
{
    int i;
    pthread_t tid[3], self_tid;
    self_tid = pthread_self();
    printf("Self thread id : [%ld]\n",self_tid);
    
    // Let us create three threads
    for (i = 0; i < 3; i++){
        pthread_create(&tid[i], NULL, myThreadFun, (void *)&tid[i]);
        pthread_join(tid[i],NULL); //waits for the thread identified by thread to terminate
    }
    pthread_exit(NULL); //terminates the calling thread
}