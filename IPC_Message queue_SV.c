// https://www.geeksforgeeks.org/ipc-using-message-queues/
// Example:
// https://www.softprayog.in/programming/interprocess-communication-using-system-v-message-queues-in-linux
// https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_message_queues.htm

/**writer**/
// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>    /* Defines O_* constants */
#include <sys/stat.h> /* Defines mode constants */
#include <mqueue.h>
#define MAX 10

// structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} message;

int main()
{
    key_t key;
    int msgid;
    system("touch msgq.txt");

    // ftok to generate unique key
    // key_t ftok(const char *path, int id);
    key = ftok("msgq.txt", 65);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    message.mesg_type = 1;
    printf("Write Data : ");
    fgets(message.mesg_text,MAX,stdin);
    //gets(message.mesg_text);

    // msgsnd to send message
    // int msgsnd(int msqid, void *msgp, size_t msgsz, int msgflg);
    /**If the IPC_NOWAIT flag is set in the msgflg parameter and the message is not sent, The msgsnd() function returns immediately with a return value of -1 and errno set to EAGAIN.

    If the IPC_NOWAIT flag is not set in the msgflg parameter, the calling thread suspends processing until one of the following occurs:

    *   Enough messages are received from the message queue so that a message of size msgsz can be placed on the message queue.
    *   The message queue identifier msqid is removed from the system. When this occurs, the msgsnd() function returns with a return value of -1 and errno set to EIDRM.
    *   A signal is delivered to the calling thread. When this occurs, the msgsnd() function returns with a return value of -1 and errno set to EINTR.
    * 
    * 
    **/
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data send is : %s \n", message.mesg_text);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
    }

    return 0;
}

// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} message;

int main()
{
    key_t key;
    int msgid;
    system("touch msgq.txt");

    // ftok to generate unique key
    key = ftok("msgq.txt", 65);

    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message
    // int msgrcv(int msgid, void *msgp, size_t msgsz, long int msgtyp, int msgflg);
    /**The argument msgtyp specifies the type of message requested, as follows:
    If msgtyp is equal to zero, the first message on the queue is received.
    If msgtyp is greater than 0, the first message of type, msgtyp, is received.
    If msgtyp is less than 0, the first message of the lowest type that is less than or equal to the absolute value of msgtyp is received.

    The fouth argument, msgtype, indicates the type of message −

    If msgtype is 0 − Reads the first received message in the queue

    If msgtype is +ve − Reads the first message in the queue of type msgtype (if msgtype is 10, then reads only the first message of type 10 even though other types may be in the queue at the beginning)

    If msgtype is –ve − Reads the first message of lowest type less than or equal to the absolute value of message type (say, if msgtype is -5, then it reads first message of type less than 5 i.e., message type from 1 to 5)

    The argument msgflg specifies the action to be taken if a message of the desired type is not on the queue. These are as follows:
    If the IPC_NOWAIT flag is on in msgflg, the calling process will return immediately with a return value of -1 and errno set to ENOMSG.
    If the IPC_NOWAIT flag is off in msgflg the calling process will suspend execution until one of the following occurs:
    A message of the desired type is placed on the queue.
    The message queue identifier, msgid, is removed from the system; when this occurs, errno is set to EIDRM and a value of -1 is returned.
    The calling process receives a signal that is to be caught; in this case a message is not received and the calling process resumes execution. A value of -1 is returned and errno is set to EINTR.**/

    msgrcv(msgid, &message, sizeof(message), 1, 0); // type of 1 will be recieved first

    // display the message
    printf("Data Received is : %s \n",
           message.mesg_text);

    // to destroy the message queue
    /**
    IPC_STAT − Copies information of the current values of each member of struct msqid_ds to the passed structure pointed by buf. This command requires read permission on the message queue.

    IPC_SET − Sets the user ID, group ID of the owner, permissions etc pointed to by structure buf.

    IPC_RMID − Removes the message queue immediately.**/
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}