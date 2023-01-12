/**
 * Process creation is achieved through the fork() system call.
 * The newly created process is called the child process and the process that initiated it (or the process when execution is started) is called the parent process. 
 * After the fork() system call, now we have two processes - parent and child processes.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//Need to learn semaphore/MQ/SM

int main() {
   int mypid, myppid, status;
   printf("Program to know PID and PPID's information\n");
   mypid = getpid(); //get process id
   //myppid = getppid();
   printf("My process ID is %d\n", mypid);
   printf("My parent process ID is %d\n", myppid);
   //printf("Cross verification of pid's by executing process commands on shell\n");
   //system("ps");
   pid_t  pid = fork();   //Not available in Windows gcc but will work in Linux
   //pid will be 0 for child process and positive for parent, -ve if child process not created
   if (pid < 0) {
      perror("fork() failure\n");
      return 1;
   }
   if (pid == 0) {
      printf("This is child process\n");
      mypid = getpid();
      sleep(10);yy
      //myppid = getppid();
      printf("Process id is %d and PPID is %d\n", mypid, myppid);
      exit(5);
   }
   else { // Parent process 
      sleep(2);
      printf("This is parent process\n");
      mypid = getpid();
      //myppid = getppid();
      printf("Process id is %d and PPID is %d\n", mypid, myppid);
      printf("Newly created process id or child pid is %d\n", pid);
      wait(&status);
   }
   printf("Called fork() system call\n");
   return 0;
}