#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line *prior;
    int data;
    struct line *next;
}line;

line *initline(line *head)
{
    head = (line *)malloc(sizeof(line*));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;

    line *list = head;

    for (int i = 2; i <= 3; i ++) {
        line *body = (line *)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        list->prior = list;

        list = list->next;
    }

    list->next = head;
    head->prior = list;

    return head;
}

void display(line *head)
{
    line *temp = head;

    while (temp->next != head) {
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        } else {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }

    printf("%d\n", temp->data);
}

int main(void)
{

    line *head = NULL;
    head = initline(head);
    display(head);
}
