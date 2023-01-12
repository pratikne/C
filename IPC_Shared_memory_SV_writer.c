//Sender
// https://www.geeksforgeeks.org/ipc-shared-memory/
// https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_shared_memory.htm

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;

#define SIZE 1024

int main()
{
    // ftok to generate unique key linked to filename, so that programs can access it
    // key_t ftok(const char *pathname, int proj_id);
    // OR directly assign new random key to key_t = 9876
    key_t key = ftok("shmfile",65);
    if(key < 0){
        perror("ftok failed");
        exit(1);
    }
    // ftok() function returns the same key value for all paths that name the same file, when called with the same id value

  
    // shmget returns an identifier in shmid
    // allocates a System V shared memory segment
    // int shmget(key_t key, size_t size, int shmflg);
    // Permission 0666 is in Octal just like we use in chmod( read and write permisison to all)
    int shmid = shmget(key, SIZE, 0666 | IPC_CREAT);
    if(shmid < 0){
        perror("shmget failed");
        exit(1);
    }
    
    // shmat to attach to shared memory
    /**The shmat() function attaches the shared memory segment associated with the shared memory identifier, shmid, to the address space of the calling process. The segment is attached at the address specified by one of the following criteria:
    If shmaddr is a NULL pointer, the segment is attached at the first available address as selected by the system.**/
    // void *shmat(int shmid, const void *shmaddr, int shmflg);
    // int shmdt(const void *shmaddr);
    char* str = (char*) shmat(shmid, NULL, 0);  //2nd para instead of (void*)0, we can pass NULL
    if(str == (char*) -1){
        perror("shmat failed");
        exit(1);
    }
  
    cout<<"Write Data : ";
    gets(str);
    //memcpy(str,"Hello World!",strlen(str));
  
    printf("Data written in memory: %s\n",str);
      
    // detaches the shared memory segment located at the address
    // specified by shmaddr from the address space of the calling process.
    shmdt(str);
  
    return 0;
}

/**NOTE
 * to check shared memory in linux
 * 
 * 
 *     ipcs -m 
 *we get key, shmid, owner, perms, bytes info 


 to remove based on shmid
 ipcs -rm {shmid}

 to remove based on key
 ipcs -M {key}

--faster than file system but surely needs thread safety such as using semaphore

*/