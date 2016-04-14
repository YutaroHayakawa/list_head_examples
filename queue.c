#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node {
    struct list_head list;
    int val;
};

void Enqueue(int num, struct list_head *head);
void Dequeue(struct list_head *head);
void Show(struct list_head *head);

int main(void) {
    struct list_head head;

    INIT_LIST_HEAD(&head);

    Enqueue(100, &head);
    Enqueue(200, &head);
    Enqueue(300, &head);
    Enqueue(400, &head);

    Show(&head);

    Dequeue(&head);
    Dequeue(&head);
    Dequeue(&head);

    Show(&head);
    return 0;
}

void Enqueue(int num, struct list_head *head)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if(!new) return;
    new->val = num;
    list_add_tail(&(new->list), head);
}

void Dequeue(struct list_head *head)
{
    struct node *entry;
    entry = list_entry(head->next, struct node, list);
    list_del(head->next);
    free(entry);
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
