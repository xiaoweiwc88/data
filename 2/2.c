#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    char elem;
    struct Link * next;
}link;

link *initlink();

void display(link *p);

int main(void)
{
    printf("init the link:\n");
    link *p = initlink();
    display(p);

    return 0;
}

link *initlink(void)
{
    link *p = NULL;     //创建头指针
    link *temp = (link *)malloc(sizeof(link)); //创建首元节点

    temp->elem = 1;
    temp->next = NULL;

    p = temp;

    for (int i = 2; i < 5; i++) {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }

    return p;
}

void display(link *p)
{
    link *temp = p;

    while (temp) {
        printf("%d  ", temp->elem);
        temp=temp->next;
    }

    printf("\n");
}
