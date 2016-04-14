#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define MAX_SLOT_SIZE 4

struct node {
    struct list_head list;
    int val;
};

struct fifo_head {
    struct list_head list;
    unsigned int counter;
};

void Enqueue(int num, struct fifo_head *head);
void Dequeue(struct fifo_head *head);
void Show(struct fifo_head *head);

int main(void) {
    struct fifo_head fifo_head;

    INIT_LIST_HEAD(&(fifo_head.list));
    fifo_head.counter = 0;

    Enqueue(100, &(fifo_head));
    Enqueue(200, &(fifo_head));
    Enqueue(300, &(fifo_head));
    Enqueue(400, &(fifo_head));
    Show(&(fifo_head));
    printf("\n");
    Dequeue(&(fifo_head));
    Dequeue(&(fifo_head));
    Dequeue(&(fifo_head));
    Enqueue(500, &(fifo_head));
    Show(&(fifo_head));
    printf("\n");
    Enqueue(600, &(fifo_head));
    Show(&(fifo_head));
    printf("\n");
    Enqueue(700, &(fifo_head));
    Show(&(fifo_head));
    printf("\n");
    Enqueue(800, &(fifo_head));
    Show(&(fifo_head));
    printf("\n");
    return 0;
}

void Enqueue(int num, struct fifo_head *head)
{
    struct node *new;

    new = malloc(sizeof(struct node));

    if(!new) return;

    new->val = num;

    if(head->counter == MAX_SLOT_SIZE) {
        list_del(head->list.next);
        list_add_tail(&(new->list), &(head->list));
        head->counter = MAX_SLOT_SIZE;
    }else {
        list_add_tail(&(new->list), &(head->list));
        head->counter++;
    }
}

void Dequeue(struct fifo_head *head)
{
    struct node *entry;

    if(head->counter == 0) return;

    entry = list_entry(head->list.next, struct node, list);
    list_del(head->list.next);
    free(entry);
    head->counter--;
}

void Show(struct fifo_head *head) {
    struct node *cursor;
    int index = 0;

    list_for_each_entry(cursor, &(head->list), list) {
        printf("[%d] %d\n", index, cursor->val);
        index++;
    }
}
