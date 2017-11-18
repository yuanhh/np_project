#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main()
{
    int i;
    struct node* head = NULL;
    struct node* node = NULL;
    int *result;

    for (i = 0; i < 100; i++) {
        int* data = calloc(1, sizeof(int));
        *data = i;
        Push(&node, data);
        Append(&head, &node);
    }

    for (i = 0; i < 100; i++) {
        result = Pop(&head);
        printf("link list length: %d\n", Length(head));
        printf("data: %d\n", *result);
        free(result);
    }

    DeleteList(&head);
}
