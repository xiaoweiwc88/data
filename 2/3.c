#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
    int elem;
    struct Link *next;
}link;

link *initlink()
{
    link *p = (link *)malloc(sizeof(link));  //创建头节点
    link *temp = p;     //声明一个指针指向头节点，用于遍历链表

    for (int i = 1; i < 5; i++) {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }

    return p;
}

link *insertelem(link *p, int elem, int add)
{
    link *temp = p;

    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("invoid insert position\n");
            return p;
        }
    }

    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;

    return p;
}

link *delelem(link *p, int add)
{
    link *temp = p;
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("no have add node\n");
            return p;
        }
    }

    link *del = temp->next;
    temp->next = temp->next->next;
    free(del);

    return p;
}

int selectelem(link *p, int elem)
{
    link *t = p;
    int i = 1;

    while (t->next) {
        t=t->next;
        if (t->elem == elem){
            return i;
        }
        i++;
    }

    return -1;
}

link *amenelem(link *p, int add, int newelem)
{
    link *temp = p;
    temp = temp->next;

    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newelem;

    return p;
}

void display(link *p)
{
    link *temp = p;

    while (temp->next) {
        temp = temp->next;
        printf("%d ",temp->elem);

    }

    printf("\n");
}


int main(void)
{
    //init linklist 1 2 3 4
    printf("init list is :\n");
    link *p = initlink();
    display(p);

    printf("insert 5 in pos 4:\n");
    p = insertelem(p, 5, 4);
    display(p);

    printf("delete elem 3:\n");
    p = delelem(p, 3);
    display(p);

    printf("find elem 2 pos is:%d\n");
    int addr = selectelem(p, 2);
    if (addr == -1) {
        printf("no element\n");
    } else {
        printf("elem 2 pos is %d\n", addr);
    }

    printf("change the postion 3 elem to 7:\n ");
    p = amenelem(p, 3, 7);
    display(p);

    return 0;
}

