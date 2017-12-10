#ifndef _SHM_H
#define _SHM_H

#include <unistd.h>

#define SHMSIZ 1024
#define FILEPATH "/tmp/mmapped.bin"

void *mmap_alloc(size_t len);
void mmap_free(void *addr);
void mmap_write(void *addr, void *src, size_t len);
void mmap_read(void *addr, void *src, size_t len);

#endif

