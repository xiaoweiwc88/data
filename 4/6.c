#include <stdio.h>
#define max 5
int enqueue(int *a, int front, int rear, int data)
{
    if ((rear + 1) % max == front) {
        printf("队列为空");
        return rear;
    }
    a[rear%max] = data;
    rear++;
    return rear;
}

int dequeue(int *a, int front, int rear)
{
    if (front == rear % max) {
        printf("队列为空");
        return front;
    }
    printf("%d ", a[front]);
    front = (front + 1) % max;

    return front;
}

int main(void)
{
    int a[max];
    int front, rear;

    front = rear = 0;

    rear = enqueue(a, front, rear, 1);
    rear = enqueue(a, front, rear, 2);
    rear = enqueue(a, front, rear, 3);
    rear = enqueue(a, front, rear, 4);

    front = dequeue(a, front, rear);
    rear = enqueue(a, front, rear, 5);
    front = dequeue(a, front, rear);
    rear = enqueue(a, front, rear, 6);

    front = dequeue(a, front, rear);
    front = dequeue(a, front, rear);
    front = dequeue(a, front, rear);
    front = dequeue(a, front, rear);

    return 0;
}
