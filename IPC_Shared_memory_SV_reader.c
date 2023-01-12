//https://www.geeksforgeeks.org/ipc-shared-memory/

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;

#define SIZE 1024
  
int main(int argc, char* argv[])
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(key, SIZE, 0666|IPC_CREAT);
  
    // shmat to attach the buffer to shared memory
    // attaches the shared memory segment associated with the shared memory identifier
    char *str = (char*) shmat(shmid, (void*)0, 0);
  
    printf("Data read from memory: %s\n",str);
      
    //detach from shared memory 
    // int shmdt(const void *shmaddr)
    shmdt(str);
    
    // destroy the shared memory
    // int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    shmctl(shmid, IPC_RMID, NULL);  //IPC_STAT, IPC_SET too are imp cmd
     
    return 0;
}