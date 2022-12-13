// https://www.thegeekstuff.com/2011/12/c-socket-programming/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[1025];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET is the address domain of the socket.
    // SOCK_STREAM TCP is a sequenced, reliable, two-way, connection-based byte stream.
    // SOCK_DGRAM UDP is a connectionless, unreliable datagrams of fixed maximum length.
    // 0 is the protocol number. The protocol number is zero to choose the default protocol appropriate for the requested socket type.
    // The socket() function returns a file descriptor for the new socket, or -1 if an error occurred.

    // memset is used to fill a block of memory with a particular value.
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    // htons converts a port number in host byte order to a port number in network byte order.
    // htonl converts the unsigned integer hostlong from host byte order to network byte order.

    // bind() assigns the address specified by addr to the socket referred to by the file descriptor sockfd.
    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // listen() marks the socket referred to by sockfd as a passive socket, that is, as a socket that will be used to accept incoming connection requests using accept().
    listen(listenfd, 10);

    while (1)
    {
        // accept() extracts the first connection request on the queue of pending connections for the listening socket, sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket.
        connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);

        while(1) {
            // time() returns the current time of the system as a time_t value.
            ticks = time(NULL);
            // snprintf() is similar to sprintf(), but will not write more than size bytes (including the terminating null byte ('\0')) to str.
            snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
            // write() writes up to count bytes from the buffer pointed buf to the file referred to by the file descriptor fd.
            write(connfd, sendBuff, strlen(sendBuff));
            // sleep() causes the calling thread to sleep until either the number of real-time seconds specified in seconds has elapsed or a signal arrives which is not ignored.
            sleep(1); 
        }
        
        close(connfd);
    }
}

// gcc time_server.c -o time_server -lpthread