#include <stdio.h>              // printf, perror
#include <sys/socket.h>         // socket()
#include <netinet/in.h>         // AF_INET
#include <netinet/ip_icmp.h>    // IPPROTO_ICMP
#include <errno.h>              // errno
#include <unistd.h>             // close()
#include "ft_ping.h"

int run_ping(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // Crée un socket RAW ICMP (AF_INET pour IPv4, SOCK_RAW pour brut, ICMP)
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("❌ Error: Cannot open raw socket");
        return 1;
    }

    printf("✅ Socket created successfully (fd = %d)\n", sockfd);
    close(sockfd);
    return 0;
}