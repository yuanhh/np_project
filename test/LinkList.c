#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "LinkList.h"

int Length(struct node* head)
{
    struct node* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int Count(struct node *head, void *searchFor)
{
    struct node *current;
    int count = 0;

    for (current = head; current != NULL; current = current->next)
        if (current->data == searchFor)
            count++;

    return count;
}

void *GetNth(struct node *head, int index)
{
    struct node *current;
    int count = 0;

    for (current = head; current != NULL; current = current->next) {
        if (count == index)
            return current->data;
        count++;
    }
    return NULL;
}

void DeleteList(struct node** headRef)
{
    struct node* current = *headRef;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

void Push(struct node** headRef, void *data)
{
    struct node* newNode =
        (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void *Pop(struct node** headRef)
{
    struct node* head = *headRef;
    void* result;

    assert(head != NULL);

    result = head->data;
    *headRef = head->next;
    free(head);

    return result;
}

void InsertNth(struct node** headRef, int index, void *data)
{
    if (index == 0)
        Push(headRef, data);
    else {
        struct node* current = *headRef;
        int i;

        for (i = 0; i < index - 1; ++i) {
            assert(current != NULL);
            current = current->next;
        }
        assert(current != NULL);
        Push(&(current->next), data);
    }
}

void* DeleteNth(struct node** headRef, int index)
{
    if (index == 0)
        return Pop(headRef);
    else {
        struct node* current = *headRef;
        int i;

        for (i = 0; i < index - 1; ++i) {
            assert(current != NULL);
            current = current->next;
        }
        assert(current != NULL);
        return Pop(&(current->next));
    }
}

void Append(struct node** aRef, struct node** bRef)
{
    struct node* current;

    if (*aRef == NULL)
        *aRef = *bRef;
    else {
        current = *aRef;
        while (current->next != NULL)
            current = current->next;

        current->next = *bRef;
    }
    *bRef = NULL;
}
