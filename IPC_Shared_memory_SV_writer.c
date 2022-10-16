//Sender
// https://www.geeksforgeeks.org/ipc-shared-memory/

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;
  
int main()
{
    // ftok to generate unique key
    // key_t ftok(const char *pathname, int proj_id);
    key_t key = ftok("shmfile",65);
    // ftok() function returns the same key value for all paths that name the same file, when called with the same id value

  
    // shmget returns an identifier in shmid
    // allocates a System V shared memory segment
    // int shmget(key_t key, size_t size, int shmflg);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    // Create a new segment
  
    // shmat to attach to shared memory
    /**The shmat() function attaches the shared memory segment associated with the shared memory identifier, shmid, to the address space of the calling process. The segment is attached at the address specified by one of the following criteria:
    If shmaddr is a NULL pointer, the segment is attached at the first available address as selected by the system.**/
    // void *shmat(int shmid, const void *shmaddr, int shmflg);
    // int shmdt(const void *shmaddr);
    char* str = (char*) shmat(shmid,(void*)0,0);
  
    cout<<"Write Data : ";
    gets(str);
  
    printf("Data written in memory: %s\n",str);
      
    // detaches the shared memory segment located at the address
    // specified by shmaddr from the address space of the calling process.
    shmdt(str);
  
    return 0;
}