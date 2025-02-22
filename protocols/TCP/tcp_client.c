#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFMAX 200    // max characters allowed in buffer
#define PORT_DEF 5123 // default port
#define MAX_CONNECTIONS 5

#define EXIT_SUCCESS 0
#define ERROR_SOCK_FAILURE -1
#define ERROR_CLIENT_SERVERCON -2

// TODO
void sigpipe_handler() {}

// Server connection loop waiting for connections on port/fd
// return negative for failure states, indicated by preproc definitions
int tcpClientIPv4(char* ip) {

  // can later determine if I want to open on different INET addresses
  // protocol currently not specified, just 0
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("failed to create socket\n");
    return ERROR_SOCK_FAILURE;
  }
  printf("Socket opened %d", sockfd);

  struct sockaddr_in serveraddr;
  // zero the addr struct out before filling:
  bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET; // accept connections in ipv4 family
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //connect to server ip
  serveraddr.sin_port = htons(PORT_DEF); //predefined port

  int conn_status =
      connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  if (conn_status < 0) {

    printf("unable to open socket to listening\n");
    return ERROR_CLIENT_SERVERCON;
  }

  printf("Client connected to server: %d\n", serveraddr.sin_addr.s_addr);

  // spin and split processes for each client?
  // while (1) {
  //   int chpid;
  //   if ((chpid = fork()) == 0) {
  //     // 0 is child
  //     break;
  //   }
  // }

  // entering back-and-forth communication

  char mbuff[BUFMAX];
  int i = 0;
  while (1) {

    // clear buffer:
    bzero(mbuff, BUFMAX);

    printf("To Server:\t");
    // clear buffer to send message back by pulling in until enter.
    // Truncating to max buffer
    char c;
    i = 0;
    while ((c = getchar()) != '\n') {
      if (i < BUFMAX - 1) {
        mbuff[i++] = c;
      }
    }
    // last buff add the \0
    mbuff[i] = '\0';

    write(sockfd, mbuff, sizeof(mbuff));

    bzero(mbuff, BUFMAX);
    // read the client connection fd to see if info sent
    int len = read(sockfd, mbuff, sizeof(mbuff));
    // if I write q\n, exit
    if (strncmp("q", mbuff, 1) == 0 || strncmp("quit", mbuff, 4) == 0) {
      strcpy(mbuff, "Server exiting\0");
      printf("Server exiting, client exit too\n");
      break;
    }
    printf("From Server: %s\n", mbuff);
  }

  close(sockfd);
  return 0;
}

int main(int argc, char *argv[]) {

  int response = tcpClientIPv4(NULL);

  if (response < 0) {
    exit(response);
  }

  exit(0);
}
