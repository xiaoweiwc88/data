#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = -1;

void push(char *a, int elem) {
    a[++top] = elem;
}
void pop(char *a) {
    if (top == -1) {
        return ;
    }
    top--;
}

char visit(char *a)
{
    if (top != -1)
        return a[top];
    else
        return ' ';
}


int main(void)
{
    char a[30];
    char bracket[100];
    printf("请输入括号序列");
    scanf("%s", bracket);
    getchar();
    int length = (int)strlen(bracket);

    for (int i = 0; i < length; i++) {
        if (bracket[i] == '(' || bracket[i] == '{') {
            push(a, bracket[i]);
        } else {
            if(bracket[i] == ')') {
                if (visit(a) == '(') {
                    pop(a);
                } else {
                    printf("括号不匹配");
                    return 0;
                } 
            } else {
                if (visit(a) == '{') {
                    pop(a);
                } else {
                    printf("括号不匹配");
                    return 0;
                }
            }
        }
    }
    if (top != -1)
        printf("括号不匹配");
    else
        printf("括号匹配");

}

