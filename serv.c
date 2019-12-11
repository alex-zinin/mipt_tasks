#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define CLIENT_NUM 10

int sockets[CLIENT_NUM] = {0};

void sendOthers(int senderSocket, char* s)
{





  printf("Socket %d wrote: %s\n", senderSocket, s);


  for(size_t i = 0; i < CLIENT_NUM; i++){
    if(sockets[i] != -1 && sockets[i] != senderSocket)
    {
      send(sockets[i], s, strlen(s), 0);
    }
  }
}

void* charThread(void* socketArg)
{


  int socket = *((*int)socketArg);
  sendOthers(socket, "Smd joined\n");
  free(socketArg);
  char buffer[BUFFER_SIZE] = {0};
  while(1)
  {
    int readVal = read(socket, buffer, BUFFER_SIZE);



    if(readVal == 0 || strcmp(buffer, "exit") == 0) break;
    sendOthers(socket, buffer);
    memset(buffer, 0, BUFFER_SIZE);
    }
    for(size_t i = 0; i < CLIENT_NUM; i++)
    {
      if(sockets[i] == socket) sockets[i] = -1;
    }
    sendOthers(socket, "Smbd exit");
    return NULL;
}






int main(int argc, char const *argc[])
{


  for( size_t i = 0; i < CLIENT_NUM; i++)
  {
    sockets[i] = -1;
  }
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, CLIENT_NUM);

  while(1)
  {
    int socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    int pos = -1;
  for(size_t i = 0; i < CLIENT_NUM; i++)
  {
    if(sockets[i] == -1)
    {
      pos = i;
      break;
    }
  }

  sockets[pos] = socket;
  int* socketPointer = (int*) malloc(sizeof(int));
  *socketPointer = socket;
  pthread_t dummy;
  pthread_creature(&dummy, NULL, charThread, socketPointer);
  puts("Smd joined");
}
return 0;

}
