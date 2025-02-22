#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFMAX 200    // max characters allowed in buffer
#define PORT_DEF 5123 // default port
#define MAX_CONNECTIONS 5

#define EXIT_SUCCESS 0
#define ERROR_SOCK_FAILURE -1
#define ERROR_BIND_FAILURE -2
#define ERROR_LISTEN_FAILURE -3
#define ERROR_ACCEPT_FAILURE -4

//TODO
void sigpipe_handler() {}

// Server connection loop waiting for connections on port/fd
// return negative for failure states, indicated by preproc definitions
int tcpServerIPv4() {

  // can later determine if I want to open on different INET addresses
  // protocol currently not specified, just 0
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("failed to create socket\n");
    return ERROR_SOCK_FAILURE;
  }

  printf("Socket opened %d\n", sockfd);

  struct sockaddr_in serveraddr;
  // zero the addr struct out before filling:
  bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET; // accept connections in ipv4 family
  serveraddr.sin_addr.s_addr =
      htonl(INADDR_ANY); // accept from any ip; htonl is "hostlong" uint32_t
  serveraddr.sin_port = htons(
      PORT_DEF); // listen on a predefined port; htons is "hostshort" uint16_t

  int bindRes =
      bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
  if (bindRes < 0) {
    printf("failed to bind to port %d accepting addresses %d for family %d\n",
           PORT_DEF, serveraddr.sin_addr.s_addr, serveraddr.sin_family);
    return ERROR_BIND_FAILURE;
  }
  printf("bind successful for port %d\n", PORT_DEF);

  // let the socket start accepting connections
  int lis = listen(sockfd, MAX_CONNECTIONS);
  if (lis == -1) {
    printf("unable to open socket to listening\n");
    return ERROR_LISTEN_FAILURE;
  }
  printf("Server listening\n");

  // accept connections from a client address
  struct sockaddr_in clientaddr;
  socklen_t addrLen = sizeof(clientaddr);
  // bzero(&clientaddr, sizeof(clientaddr));

  int clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrLen);

  if (clientfd < 0) {
    printf("server couldn't accept request\n");
    return ERROR_ACCEPT_FAILURE;
  }
  printf("Client connecting: %d\n", clientaddr.sin_addr.s_addr);

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

    // read the client connection fd to see if info sent
    int len = read(clientfd, mbuff, sizeof(mbuff));
    printf("From Client: %s\n", mbuff);

    printf("To Client:\t");
    //clear buffer to send message back by pulling in until enter.
    //Truncating to max buffer
    bzero(mbuff, BUFMAX);
    char c;
    i = 0;
    while ((c = getchar()) != '\n') {
      if (i < BUFMAX -1) {
        mbuff[i++] = c;
      }
    }
    //last buff add the \0
    mbuff[i] = '\0';

    //if I write q\n, exit
    if (strncmp("q", mbuff, 1) == 0 || strncmp("quit", mbuff, 4) == 0) {
      strcpy(mbuff, "Server exiting\0");
      printf("%s\n", mbuff);
      write(clientfd, mbuff, sizeof(mbuff));
      close(clientfd);
      break; 
    }

    write(clientfd, mbuff, sizeof(mbuff));
  }

  close(sockfd);
  return 0;
}

int main(int argc, char *argv[]) {

  int response = tcpServerIPv4();

  if (response < 0) {
    exit(response);
  }

  exit(0);
}
