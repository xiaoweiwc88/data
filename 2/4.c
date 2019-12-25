#include <stdio.h>
#define MAXSIZE 7

typedef struct {
    int data;
    int cur;
}component;

void reserverarr(component *array)
{
    int i;

    for (i = 0; i < MAXSIZE; i++) {
        array[i].cur = i + 1;
        array[i].data = -1;
    }

    array[MAXSIZE - 1].cur = 0;
}

int mallocarr(component *array)
{
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }

    return i;
}

int initarr(component *array)
{
    reserverarr(array);
    int body = mallocarr(array);

    int tempbody = body;
    for (int i = 1; i < 5; i++) {
        int j = mallocarr(array);
        array[tempbody].cur = j;
        array[j].data = 'a' + i - 1;
        tempbody = j;
    }

    array[tempbody].cur = 0;
    return body;
}

void display(component *array, int body)
{
    int tempbody = body;

    while (array[tempbody].cur) {
        printf("[%c, %d]  ", array[tempbody].data, array[tempbody].cur);
        tempbody = array[tempbody].cur;
    }

    printf("[%c, %d]\n", array[tempbody].data, array[tempbody].cur);
}

void insertarr(component *array, int body, int add, char a)
{
    int tempbody = body;

    for (int i = 1; i < add; i++) {
        tempbody = array[tempbody].cur;
    }

    int insert = mallocarr(array);
    array[insert].data = a;

    array[insert].cur = array[tempbody].cur;
    array[tempbody].cur = insert;
}

void freearr(component *array, int k)
{
    array[k].cur = array[0].cur;
    array[0].cur = k;
}

void deletarr(component *array, int body, char a)
{
    int tempbody = body;

    while (array[tempbody].data != a) {
        tempbody = array[tempbody].cur;
        if (tempbody == 0)  {
            printf("list have no this data\n");
            return ;
        }
    }

    int del = tempbody;
    tempbody = body;

    while(array[tempbody].cur != del) {
        tempbody = array[tempbody].cur;
    }

    array[tempbody].cur = array[del].cur;

    freearr(array, del);
}

int selectelem(component *array, int body, char elem)
{
    int tempbody = body;

    while (array[tempbody].cur != 0) {
        if (array[tempbody].data == elem)
            return tempbody;
        tempbody = array[tempbody].cur;
    }

    return -1;
}

void amendelem(component *array, int body, char oldelem, char newelem)
{
    int add = selectelem(array, body, oldelem);
    if (add == -1) {
        printf("no change elem\n");
        return ;
    }

    array[add].data = newelem;
}

int main(void)
{
    component array[MAXSIZE];

    int body = initarr(array);
    printf("body = %d\n", body);
    printf("static list is:\n");
    display(array, body);

    printf("insert 'e' in pos 3:\n");
    insertarr(array, body, 3, 'e');
    display(array, body);

    printf("delete the node of 'a':\n");
    deletarr(array, body, 'a');
    display(array, body);

    printf("find the pos of 'e':");
    int selectadd = selectelem(array, body, 'e');
    printf("%d\n", selectadd);


    printf("change date 'e' to 'h':\n");
    amendelem(array, body, 'e', 'h');
    display(array, body);

    return 0;
}
