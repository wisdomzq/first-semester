#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  
   
//跑道结构  
typedef struct{  
    int freetime;  
    int totaltime;  
}RunwayType;  
RunwayType runway[105];  
   
//飞机结构  
typedef struct _airplane{  
    int airplaneID;  
    int time;  
    struct _airplane *next;  
}AirplaneType;  
AirplaneType airplane;  
   
//降落队列  
AirplaneType *landhead = NULL;  
AirplaneType *landtail = NULL;  
void createlandqueue(){  
    AirplaneType *p;  
    p = (AirplaneType *)malloc(sizeof(AirplaneType));  
    p->next = NULL;  
    p->airplaneID = -1;  
    p->time = -1;  
    landhead = p;  
    landtail = p;  
}  
void addlandqueue(int number, int time){  
    AirplaneType *p;  
    p = (AirplaneType *)malloc(sizeof(AirplaneType));  
    p->next = NULL;  
    p->airplaneID = number;  
    p->time = time;  
    landtail->next = p;  
    landtail = landtail->next;  
}  
AirplaneType outlandqueue(){  
    AirplaneType *p;  
    p = landhead->next;  
    landhead->next = p->next;  
    if(landhead->next == NULL)  
        landtail = landhead;  
    return *p;  
}  
//起飞队列  
AirplaneType *offhead = NULL;  
AirplaneType *offtail = NULL;  
void createoffqueue(){  
    AirplaneType *p;  
    p = (AirplaneType *)malloc(sizeof(AirplaneType));  
    p->next = NULL;  
    p->time = -1;  
    p->airplaneID = -1;  
    offhead = p;  
    offtail = p;  
}  
void addoffqueue(int number, int time){  
    AirplaneType *p;  
    p = (AirplaneType *)malloc(sizeof(AirplaneType));  
    p->next = NULL;  
    p->time = time;  
    p->airplaneID = number;  
    offtail->next = p;  
    offtail = offtail->next;  
}  
AirplaneType outoffqueue(){  
    AirplaneType *p;  
    p = offhead->next;  
    offhead->next = p->next;  
    if(offhead->next == NULL)  
        offtail = offhead;  
    return *p;  
}  
//判断队列是否为空  
int isempty(AirplaneType *p){  
    if(p->next == NULL)  
        return 1;  
    else return 0;  
}  
   
int main(int argc, char const *argv[])  
{  
    int totalrunway, landcost, offcost;  
    int currenttime = 0;  
    int landnumber, offnumber, finish = 0;  
    int landstartnumber = 5001, offstartnumber = 1;  
    int allrunwayfree = 1;  
    int landwait = 0, offwait = 0;  
    int land_number = 0, off_number = 0;  
    int runway_totaltime = 0;  
    scanf("%d%d%d",&totalrunway,&landcost,&offcost);  
    for(int i = 1; i <= totalrunway; i++){  
        runway[i].freetime = 0;  
        runway[i].totaltime = 0;  
    }  
   
    createlandqueue();  
    createoffqueue();  
    printf("Current Time: %4d\n",currenttime++);  
    while(1){  
        if(finish != 1){  
            scanf("%d%d",&landnumber,&offnumber);  
            if(landnumber < 0 && offnumber < 0){  
                finish = 1;  
            }  
        }  
          
        for(int i = 0; i < landnumber; i++){  
            addlandqueue(landstartnumber++, currenttime);  
            land_number++;  
        }  
        for(int i = 0; i < offnumber; i++){  
            addoffqueue(offstartnumber++, currenttime);  
            off_number++;  
        }  
   
        for(int i = 1; i <= totalrunway; i++){  
            if(runway[i].freetime == 0){  
                //如果有下降的飞机  
                if(!isempty(landhead)){  
                    airplane = outlandqueue();  
                    runway[i].freetime = landcost;  
                    printf("airplane %04d is ready to land on runway %02d\n", airplane.airplaneID, i);  
                    landwait = landwait + currenttime - airplane.time;  
                    runway[i].totaltime += landcost;  
                }  
                else if(!isempty(offhead)){  
                    airplane = outoffqueue();  
                    runway[i].freetime = offcost;  
                    printf("airplane %04d is ready to takeoff on runway %02d\n", airplane.airplaneID, i);  
                    offwait = offwait + currenttime - airplane.time;  
                    runway[i].totaltime += offcost;  
                }  
            }  
        }  
        printf("Current Time: %4d\n",currenttime++);  
        allrunwayfree = 1;  
        for(int i = 1; i <= totalrunway; i++){  
            if(runway[i].freetime != 0){  
                if(!(--runway[i].freetime))  
                    printf("runway %02d is free\n", i);  
                else  
                    allrunwayfree = 0;  
            }  
        }  
          
        if(finish && isempty(landhead) && isempty(offhead) && allrunwayfree)  
            break;  
    }  
      
    //输出最后结果  
    printf("simulation finished\n");  
    printf("simulation time: %4d\n", --currenttime);  
    double land_average = (double)landwait / land_number;  
    printf("average waiting time of landing: %4.1f\n", land_average);  
    double off_average = (double)offwait / off_number;  
    printf("average waiting time of takeoff: %4.1f\n", off_average);  
    for(int i = 1; i <= totalrunway; i++){  
        printf("runway %02d busy time: %4d\n", i, runway[i].totaltime);  
        runway_totaltime += runway[i].totaltime;  
    }  
    float pertime = ((float)runway_totaltime) / totalrunway * 100 / currenttime;  
    printf("runway average busy time percentage: %4.1f%%\n", pertime);  
   
    return 0;  
}  
