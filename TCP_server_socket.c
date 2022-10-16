#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr

int main(int argc , char *argv[])
{
	int socket_desc , new_socket , c;
	struct sockaddr_in server , client;
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("bind failed");
	}
	puts("bind done");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (new_socket<0)
	{
		perror("accept failed");
	}
	
	puts("Connection accepted");

    //Get ip address and port of connected client*
    char *client_ip = inet_ntoa(client.sin_addr);
    int client_port = ntohs(client.sin_port);
	
	//Reply to the client
	message = "Hello Client , I have received your connection. But I have to go now, bye\n";
	write(new_socket , message , strlen(message));

	return 0;
}

/**
Program output

Run the program. It should show

bind done
Waiting for incoming connections...
So now this program is listening for incoming connections on port 8888. Dont close this program , keep it running.
Now a client can connect to it on this port. We shall use the telnet client for testing this. Open a terminal and type

$ telnet localhost 8888
On the terminal you shall get

Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Connection closed by foreign host.
And the server output will show

bind done
Waiting for incoming connections...
Connection accepted
**/