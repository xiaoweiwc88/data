#include <stdio.h>

int enqueue(int *a, int rear, int data)
{
    a[rear] = data;
    rear++;
    return rear;
}

void dequeue(int *a, int front, int rear)
{
    while (front != rear) {
        printf("出对元素:%d\n", a[front]);
        front++;
    }
}


int main(void)
{
    int a[100];
    int front, rear;
    front = rear = 0;

    rear = enqueue(a, rear, 1);
    rear = enqueue(a, rear, 2);
    rear = enqueue(a, rear, 3);
    rear = enqueue(a, rear, 4);

    dequeue(a, front, rear);

    return 0;
}
