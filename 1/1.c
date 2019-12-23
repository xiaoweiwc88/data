#include <stdio.h>
#include <stdlib.h>

#define SIZE    5

typedef struct Table {
    int *head;
    int length;
    int size;
}table;

table inittable()
{
    table t;
    t.head = (int *)malloc(SIZE * sizeof(int));

    if (!t.head) {
        printf("init error\n");
        exit(0);
    }
    t.length = 0;
    t.size = SIZE;

    return t;
}

table addtable(table t, int elem, int add) {
    int i;
    if (add > t.length + 1 || add < 1) {
        printf("insert wrong pos\n");
        return t;
    }

    if (t.length == t.size) {
        t.head = (int *)realloc(t.head, (t.size + 1)*sizeof(int ));
        if (!t.head){
            printf("realloc is failed\n");
            return t;
        }
        t.size += 1;
    }
    
    for (i = t.length - 1; i >= add -1; i--) {
        t.head[i + 1] = t.head[i];
    }
    t.head[add -1] = elem;
    t.length++;

    return t;
}

table deltable(table t, int add)
{
    if (add > t.length || add < 1) {
        printf("delete pos is wrong\n");
        return t;
    }

    for (int i = add; i < t.length; i++)
        t.head[i - 1] = t.head[i];

    t.length--;

    return t;
}

int selecttable(table t, int elem)
{
    int i;
    
    for (i = 0; i < t.length; i++) {
        if (t.head[i] == elem)
            return i + 1;
    }

    return -1;
}

table amendtable(table t, int elem, int newele)
{
    int add;

    add = selecttable(t, elem);
    t.head[add -1] = newele;

    return t;
}


void displaytable(table t)
{
    int i;
    for (i = 0; i < t.length; i++)
        printf("%d  ", (t.head)[i]);

    printf("\n");
}

int main(void)
{
    table t;
    int i;

    t = inittable();

    for (i = 1; i <= SIZE; i++) {
        t.head[i - 1] = i;
        t.length++;
    }
    printf("original order:\n");
    displaytable(t);

    printf("delete element  1 :\n");
    t = deltable(t, 1);
    displaytable(t);

    printf("insert  5 into the 2 postion :\n");
    t = addtable(t, 5, 2);
    displaytable(t);

    printf("search the pos of 3:\n");
    int add = selecttable(t, 3);
    printf("pos of 3 is %d:\n", add);

    printf("change element 3 to 6:\n");
    t = amendtable(t, 3, 6);
    displaytable(t);

    return 0;
}


