#ifndef _LINK_LIST_H
#define _LINK_LIST_H

struct node {
    void *data;
    struct node *next;
};

int Length(struct node* head);
int Count(struct node* head, void* searchFor);
void *GetNth(struct node *head, int index);
void DeleteList(struct node** headRef);
void Push(struct node** headRef, void *data);
void *Pop(struct node** headRef);
void InsertNth(struct node** headRef, int index, void *data);
void *DeleteNth(struct node** headRef, int index);
void Append(struct node** aRef, struct node** bRef);

#endif
