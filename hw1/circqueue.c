#include <stdio.h>
#include <stdlib.h>

#include "include/circqueue.h"

struct circqueue *q(int cap, size_t siz) {
   struct circqueue *q=malloc(sizeof(struct circqueue));
   if(!q)return NULL;
   q->capacity=cap;
   q->front=-1;
   q->rear=-1;
   q->array=malloc(q->capacity*siz);
   if(!q->array)return NULL;
  return q;
}

int isemptyqueue(struct circqueue *q) {
   return(q->front==-1);
}

int isfullqueue(struct circqueue *q) {
   return((q->rear+1)%q->capacity==q->rear);
}

int queuesize(struct circqueue *q) {
   return(q->capacity-q->rear+q->front+1)%q->capacity;
}

void enqueue(struct circqueue *q,int x) {

   if(isfullqueue(q))
      printf("queue overflow\n");
   else{
      q->rear=(q->rear+1)%q->capacity;
      q->array[q->rear]=x;
      if(q->front==-1) {
         q->front=q->rear;
      }
   }
}

int dequeue(struct circqueue *q) {
   int data=0;

   if(isemptyqueue(q)) {
      fprintf(stderr, "queue underflow");
      return 0;
   }
   else {
      data=q->array[q->front];
      if(q->front==q->rear)
         q->front=q->rear=-1;
      else
         q->front=(q->front+1)%q->capacity;
   }

   return data;
}
