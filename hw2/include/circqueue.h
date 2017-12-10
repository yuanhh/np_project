#ifndef _CIRCQUEUE_H
#define _CIRCQUEUE_H

struct circqueue {
   int front,rear;
   int capacity;
   void *array;
};

#endif
