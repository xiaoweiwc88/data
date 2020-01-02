#include <stdio.h>
#include <stdlib.h>

typedef struct linestack{
    int data;
    struct linestack *next;
}linestack;

linestack *push(linestack *stack, int a)
{
    linestack *line = (linestack *)malloc(sizeof(linestack));
    line->data = a;

    line->next = stack;
    stack = line;

    return stack;
}

linestack *pop(linestack *stack)
{
    if (stack) {
        linestack *p = stack;
        stack = stack->next;
        printf("pop elem:%d  ", p->data);
        if (stack){
            printf("new pop elem:%d\n", stack->data);
        } else {
            printf("stack is empty.\n");
        }
        free(p);
    } else {
        printf("stack have no elem:\n");
        return stack;
    }

    return stack;
}


int main(void)
{
    linestack *stack = NULL;
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    stack = push(stack, 4);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);

    return 0;
}

