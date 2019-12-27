#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line *prior;
    int data;
    struct line *next;
}line;

line *initline(line *head)
{
    head = (line *)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line * list = head;

    for (int i = 2; i <=5; i++) {
        line *body  = (line *)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;
        list = list->next;
    }

    return head;
}

void display(line *head)
{
    line *temp = head;

    while (temp) {
        if (temp->next == NULL) 
            printf("%d\n", temp->data);
        else
            printf("%d <-->", temp->data);

        temp = temp->next;
    }
}

line *insertline(line *head, int data, int add)
{
    line *temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;

    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    } else {
        line *body = head;

        for (int i = 1; i < add - 1; i++) {
            body = body->next;
        }

        if (body->next == NULL) {
            body->next = temp;
            temp->prior = body;
        } else {
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
    }

    return head;
}

line *deline(line *head, int data)
{
    line *temp = head;

    while (temp) {
        if (temp->data == data) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    printf("the list have no data");

    return head;
}

int selectelem(line *head, int elem)
{
    line *t = head;
    int i = 1;

    while(t) {
        if (t->data == elem){
            return i;
        }
        i++;
        t = t->next;
    }

    return -1;
}

line *amendelem(line *p, int add, int newelem)
{
    line *temp = p;

    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }

    temp->data = newelem;
    return p;
}


int main(void)
{
    line *head = NULL;
    
    head = initline(head);
    display(head);

    //insert elem in pos 3
    head = insertline(head, 7, 3);
    display(head);

    printf("delete elem 2\n");
    head = deline(head, 2);
    display(head);

    printf("the 3 elem pos is :%d\n", selectelem(head, 3));

    //change the 3 elem to 6
    head = amendelem(head, 3, 6);
    display(head);

    return 0;
}

