#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

struct token_node {
    struct list_head list;
    char *token;
};

bool split(struct list_head *head, char *str, char *sep);

int main(void) {
    struct list_head head;
    struct token_node *cursor;
    char str[] = "hogehoge,mogemoge,foofoo,barbar, ";

    INIT_LIST_HEAD(&head);

    if(split(&head, str, ",")) {
        list_for_each_entry(cursor, &(head), list) {
            printf("%s\n", cursor->token);
        }
    }
    return 0;
}

bool split(struct list_head *head, char *str, char *sep)
{
    char *tp;
    struct token_node *new;

    tp = strtok(str, sep);

    if(tp != NULL) {
        new = malloc(sizeof(struct token_node));
        if(!new) return false;
        new->token = tp;
        list_add_tail(&(new->list), head);
    }

    while(tp != NULL) {
        tp = strtok(NULL, sep);
        if(tp != NULL) {
            new = malloc(sizeof(struct token_node));
            if(!new) return false;
            new->token = tp;
            list_add_tail(&(new->list), head);
        }
    }
    return true;
}
