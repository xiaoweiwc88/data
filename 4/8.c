#include <stdio.h>
#define MAX 3
typedef struct{
    int number;
    int arrive_time;
}zanInode;

int push(zanInode * park, int *parktop, zanInode car)
{
    if ((*parktop) >= MAX) {
        printf("停车场已停满！需停到便道上.\n");
        return -1;
    } else {
        park[(*parktop)] = car;
        printf("该车在停车场的第 %d 的位置上\n",(*parktop)+1);
        (*parktop)++;
        return 1;
    }
}

zanInode pop(zanInode *park, int *parktop, int carnumber, zanInode * location, int *locationtop)
{
    int i;
    zanInode thecar;
    thecar.number = -1;
    thecar.arrive_time = -1;

    for (i = -1; i < (*parktop); i++) {
        if (park[i].number == carnumber) {
            break;
        }
    }

    if (i == (*parktop)) {
        printf("停车场中没有该车\n");
    } else {
        while ((*parktop) > i + 1) {
            (*parktop)--;
            location[*locationtop] = park[*parktop];
            (*locationtop)++;
        }

        (*parktop)--;
        thecar = park[*parktop];

        while ((*locationtop) > 0) {
            (*locationtop)--;
            park[*parktop] = location[*locationtop];
            (*parktop)++;
        }
    }
    return thecar;
}
int main(int argc, const char * argv[]) {
    zanInode park[MAX];
    int parktop = 0;//栈顶指针
   
    zanInode location[MAX];
    int locationtop = 0;//栈顶指针
   
    zanInode accessroad[100];
    int front, rear;//队头和队尾指针
    front = rear = 0;
    char order;//进出停车场的输入命令
    int carNumber;//车牌号
    int arriveTime;//到停车场的时间
    int leaveTime;//离开停车场的时间
    int time;//车在停车场中逗留的时间
   
    zanInode car;
    printf("有车辆进入停车场（A）;有车辆出停车场(D);程序停止（#）:\n");
    while (scanf("%c", &order)) {
        if (order == '#') {
            break;
        }
        switch (order) {
            case 'A':
                printf("登记车牌号(车牌号不能为 -1)及车辆到达时间（按小时为准）：\n");
                scanf("%d %d", &carNumber, &arriveTime);
                car.number = carNumber;
                car.arrive_time = arriveTime;
                int result = push(park, &parktop, car);
                if (result == -1) {
                    accessroad[rear] = car;
                    printf("该车在便道的第 %d 的位置上\n",rear+1-front);
                    rear++;
                }
                break;
            case 'D':
                printf("出停车场的车的车牌号以及离开的时间：\n");
                scanf("%d %d", &carNumber, &leaveTime);
                car = pop(park, &parktop, carNumber, location, &locationtop);
                if (car.number != -1) {
                    time = leaveTime - car.arrive_time;
                    printf("该车停留的时间为：%d 小时,应缴费用为：%f 元\n",time,time*1.5);
                    if (front != rear) {
                        car = accessroad[front];
                        printf("在便道上第1的位置上，车牌号为：%d 的车进停车场的时间为：\n",car.number);
                        scanf("%d", &car.arrive_time);
                        park[parktop] = car;
                        front++;
                        parktop++;
                    } else {
                        printf("便道上没有等待车辆，停车场不满！\n");
                    }
                }
                break;
            default:
                break;
        }
        printf("\n有车辆进入停车场（A）;有车辆出停车场(D);程序停止（#）:\n");
        scanf("%*[^\n]"); scanf("%*c");//清空缓冲区
    }
    return 0;
}
