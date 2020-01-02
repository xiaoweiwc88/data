#include <stdio.h>
#define MAX 3
typedef struct {
    int number;
    int arrive_time;
}zaninode;

int push(zaninode * park, int * parktop, zaninode car)
{
    if ((*parktop) >= MAX) {
        printf("park is full, need to park in sidewalk\n");
        return -1;
    } else {
        park[(*parktop)] = car;
        printf("the car is in the %d pos!\n", (*parktop) + 1);
        (*parktop)++;
        return 1;
    }
}

zaninode pop(zaninode *park, int *parktop, int carnumber, zaninode * location, int *locationtop)
{
    int i;
    zaninode thecar;
    thecar.number = -1;
    thecar.arrive_time = -1;

    for (i = -1; i < (*parktop); i++) {
        if (park[i].number == carnumber) {
            break;
        }
    }

    if (i == (*parktop)) {
        printf("Park have no car\n");
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
    zaninode park[MAX];
    int parktop = 0;

    zaninode location[MAX];
    int locationtop = 0;

    zaninode accessroad[100];
    int front, rear;
    front = rear = 0;
    char order;
    int carnumber;
    int arrivetime;
    int leavetime;
    int time;

    zaninode car;
    printf("car drive into Park(A), car drive ourt from Park(D): routine terminate(#)\n");
    while (scanf("%c", &order)) {
        if (order == '#') {
            break;
        }
        switch (order) {
            case 'A':
                printf("Registered car number (the car number cannot be -1) and the arrival time of the vehicle (based on the hour):\n");
                scanf("%d %d", &carnumber, &arrivetime);
                car.number = carnumber;
                car.arrive_time = arrivetime;
                int result = push(park, &parktop, car);
                if (result == -1) {
                    accessroad[rear] = car;
                    printf("tha car park in the %d pos at accessroad\n", rear + 1 - front);
                    rear++;
                }
                break;
            case 'D':
                printf("car number leaving the parking lot and departure time\n");
                scanf("%d %d", &carnumber, &leavetime);;
                car = pop(park, &parktop, carnumber, location, &locationtop);
                if (car.number != -1) {
                    time = leavetime - car.arrive_time;
                    printf("park time is:%d h, pay is %f yuan\n", time, time * 1.5);
                    if (front != rear) {
                        car = accessroad[front];
                        printf("the car num :%d is in the accessroad time is:\n", car.number);
                        scanf("%d", &car.arrive_time);
                        park[parktop] = car;
                        front++;
                        parktop++;
                    } else {
                        printf("tha accessroad has no waiting car, the park no full\n");
                    }
                }
                break;
            default:
                break;
        }
        printf("\ncar drive into Park(A), car drive ourt from Park(D): routine terminate(#)\n");
        scanf("%*[^\n]"); scanf("%*c");
    }
    return 0;
}
