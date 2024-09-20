#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  
int jie;  
void change(int n,int m,NODE *head)  
{  
    bool judge=true;  
    int divide,num[3000],ji=2,op=1,ans[3000];//num为余数，ans为除数  
    int imp;//imp记录出现循环节的位置  
    num[1]=n;  
    while(judge)  
    {  
    divide=num[ji-1]*10%m;//余数，余数循环时就判断循环节  
    n=num[ji-1]*10/m;  
    num[ji]=divide;  
    if(divide==0)break;  
    ans[op]=n;  
    for(int i=1;i<ji;i++)  
     {  
       if(divide==num[i])   
       {  
        imp=i;judge=false;break;  
       }  
     }  
     ji++,op++;  
    if(judge==false)  
     {  
        jie=ji-imp-1;  
        bool ex=true;  
         NODE *q1;   
        for(int i=imp;i<ji-1;i++)//重构链表  
        {  
             NODE *q ;  
              q= (NODE *)malloc( sizeof(NODE) );    
             q->data=ans[i];  
            if(ex==true)   
            {  
                q->next=head->next;head->next=q;ex=false;}  
            else {  
                q->next=q1->next;q1->next=q;  
            }  
            q1=q;  
            q->next=NULL;  
        }  
        q1->next=head->next;//循环  
     }  
    }   
}    
NODE * find( NODE * head, int * n )  
{  
    NODE *p;  
    p =head->next;  
    *n=jie;  
    return p;  
}  
