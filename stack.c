#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node {
    struct list_head list;
    int val;
};

void Push(int num, struct list_head *head);
void Pop(struct list_head *head);
void Show(struct list_head *head);

int main(void) {
    struct list_head head;

    INIT_LIST_HEAD(&head);

    Push(100, &head);
    Push(200, &head);
    Push(300, &head);
    Push(400, &head);

    Show(&head);

    printf("\n");

    Pop(&head);
    Pop(&head);

    Show(&head);

    return 0;
}

void Push(int num, struct list_head *head)
{
    struct node *new;

    new = malloc(sizeof(struct node));

    if(!new) return;

    new->val = num;

    list_add(&(new->list), head);
}

void Pop(struct list_head *head)
{
    list_del(head->next);
}

void Show(struct list_head *head)
{
    struct node *cursor;
    int index = 0;

    list_for_each_entry(cursor, head, list) {
        printf("[%d] %d\n", index, cursor->val);
        index++;
    }
}
