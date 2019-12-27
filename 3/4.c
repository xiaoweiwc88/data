#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct gambler{
    int number;
}gambler;


int main(void)
{
    int n;
    int round = 1;
    int location = 1;
    int shootnum;
    int i, j;

    srand((int)(time(0)));
    printf("输入读取的人数（<100>):");
    scanf("%d", &n);
    printf("将读取一次编号为1-%d\n", n);
    gambler gamblers[100];

    for (i = 1; i <= n; i++) {
        gamblers[i].number = i;
    }

    while (n != 1) {
        printf("第 %d 轮开始，从编号为%d的人开始, ", round, gamblers[location].number);
        shootnum = rand() % 6 + 1;
        printf("抢在第%d次扣动扳机时会响\n",shootnum);
        for (i = location; i < location + shootnum; i++)
            ;
        i = i % n;
        if (i == 1 || i == 0) {
            i = n + i;
        }

        printf("编号为%d的赌徒退出赌博，剩下赌徒编号依次为:\n", gamblers[i - 1].number);
        for (j = i - 1; j + 1 < n; j++) {
            gamblers[j] = gamblers[j + 1];
        }
        n--;
        for (int k = 1; k <= n; k++) {
            printf("%d ", gamblers[k].number);
        }
        printf("\n");
        location = i - 1;
        if (location > n)
            location %= n;

        round++;
    }

    printf("最终胜利的赌徒编号是:%d\n", gamblers[1].number);

    return 0;
}
