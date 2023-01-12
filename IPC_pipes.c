// https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_pipes.htm
#include <stdio.h>
#include <unistd.h> //IMP

int main()
{
    int pipefds[2];
    int returnstatus;
    char writemessages[2][20] = {"Hi", "Hello"};
    char readmessage[20];

    //A pipe can be created using pipe() function which returns two file descriptors, one is for reading and another is for writing
    //Data can be fetched in FIFO, First In First Out manner.
    returnstatus = pipe(pipefds); //IMP

    if (returnstatus == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }

    printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
    write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe – Message 1 is %s\n", readmessage);
    printf("Writing to pipe - Message 2 is %s\n", writemessages[0]);
    write(pipefds[1], writemessages[1], sizeof(writemessages[0]));
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe – Message 2 is %s\n", readmessage);

    int pid = fork();
   
   // Child process
   if (pid == 0) {
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Child Process - Reading from pipe – Message 1 is %s\n", readmessage);
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Child Process - Reading from pipe – Message 2 is %s\n", readmessage);
   } else { //Parent process
      printf("Parent Process - Writing to pipe - Message 1 is %s\n", writemessages[0]);
      write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
      printf("Parent Process - Writing to pipe - Message 2 is %s\n", writemessages[1]);
      write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
   }

    return 0;
}