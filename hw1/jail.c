#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

    void
jail(char *path)
{
    if (chdir(path) < 0)
        perror("chdir");
    if (chroot(path) < 0)
        perror("chroot");
}
