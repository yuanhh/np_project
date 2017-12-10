#include <stdio.h>
#include <string.h>

#include "include/shm.h"

#define SHMSIZ 1024

int main()
{
    char *shm;
    char buf[BUFSIZ] = {0};

    shm = mmap_alloc(SHMSIZ);

    mmap_write(shm, "Hello World!\n", SHMSIZ);
    mmap_read(shm, buf, SHMSIZ);

    printf("%s", buf);

    mmap_free(shm);
}
