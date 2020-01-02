#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top = -1;
void push(char *a, char elem)
{
    a[++top] = elem;
}

void pop(char *a)
{
    if (top == -1)
        return;
    if (a[top] >= 10) {
        printf("%c",a[top] + 55);
    } else {
        printf("%d", a[top]);
    }
    top--;
}

int scalefun(char *data, int system)
{
    int k = (int)strlen(data) - 1;
    int system_10_data = 0;
    int i;

    for (i = k; i >= 0; i--) {
        int temp;
        if (data[i] >= 48 && data[i] <= 57)
            temp = data[i] - 48;
        else 
            temp = data[i] - 55;
        system_10_data += temp * pow(system, k - i);
    }

    return system_10_data;
}

int main(void)
{
    char data[100];
    int system;
    printf("进制转换器，请输入原数据的进制（２－３６）：");
    scanf("%d", &system);
    getchar();

    printf("请输入要转换的数据:");
    scanf("%s", data);
    getchar();

    int system_10_data = scalefun(data, system);
    printf("请输入转换后的数据的进制：");
    int newsystem;
    scanf("%d", &newsystem);
    getchar();

    while (system_10_data/newsystem) {
        push(data, system_10_data % newsystem);
      system_10_data /= newsystem;
    }
    push(data, system_10_data % newsystem);
    printf("转换后的结果为: \n");
    while (top != -1) {
        pop(data);
    }

    return 0;
}
