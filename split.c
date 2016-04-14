#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

struct token_node {
    struct list_head list;
    char *token;
};

bool split(struct list_head *head, char *str, char *separator);

int main(void) {
    struct list_head head;
    struct token_node *cursor;
    char *str = "hogehoge,mogemoge,foofoo,barbar";

    INIT_LIST_HEAD(&head);

    if(split(&head, str, ",")) {
        printf("split() done\n");
        list_for_each_entry(cursor, &(head), list) {
            puts(cursor->token);
        }
    }
    return 0;
}

bool split(struct list_head *head, char *str, char *sep)
{
    char *tp;
    struct token_node *new;

    tp = strtok(str, sep);
    printf("%p\n", tp);
    while(tp != NULL) {
        printf("loop\n");
        new = malloc(sizeof(struct token_node));
        if(!new) return false;
        new->token = tp;
        list_add_tail(&(new->list), head);
    }
    return true;
}
