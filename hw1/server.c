#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include "include/jail.h"
#include "include/inet.h"
#include "include/process.h"

#define PORT "7000"

int main()
{
    int     server_fd, conn_fd;
    char    *RAS[12] = {"ras", 0};

    setenv("PATH", ".", 1);

    server_fd = passive_tcp(NULL, PORT);

    while (1) {
        conn_fd = accept_tcp(server_fd);
        if (conn_fd < 0) break;

        process(RAS, conn_fd, conn_fd, conn_fd, 0);

        close(conn_fd);
    }
    close(server_fd);
}
