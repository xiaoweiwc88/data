#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false, true} bool;

typedef struct line {
    int no;
    struct line *next;
}line;

line * initline(int n)
{
    line * head;
    head= (line *)malloc(sizeof(line));
    head->next = NULL;
    head->no = 1;

    line *list = head;

    for (int i = 1; i < n; i++) {
        line *body = (line *)malloc(sizeof(line));
        body->next = NULL;
        body->no = i + 1;
        list->next = body;
        list = list->next;
    }

    list->next = head;

    return head;
}

void display(line *head)
{
    line *temp = head;
    while (temp->next != head) {
        printf("%d ", temp->no);
        temp = temp->next;
    }
    printf("%d\n", temp->no);
}

int main(void)
{
    line *head = NULL;
    srand((int)(time(0)));
    int n, shootnum, round = 1;

    printf("输入赌徒数:");
    scanf("%d", &n);
    head = initline(n);
    line *linenext = head;

    while (head->next != head) {
        printf("第 %d 轮开始，从编号为%d的人开始, ", round, linenext->no);
        shootnum = rand() % 6 + 1;
        printf("抢在第%d次扣动扳机时会响\n",shootnum);
        line *temp = linenext;
        for (int i = 1; i < shootnum; i++) {
            temp = temp->next;
        }
        printf("编号为%d的赌徒退出赌博，剩下赌徒编号依次为:\n", temp->next->no);
        line *del = temp->next;
        temp->next = temp->next->next;
        if (del == head) {
            head = head->next;
        }
        free(del);
        display(head);
        linenext=temp->next;
        round++;
    }
    printf("最终胜利的赌徒编号是:%d\n", head->no);

    return 0;
}
