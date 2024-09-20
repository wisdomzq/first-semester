#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
   bool judge = false;
    while ( head->next != NULL )  
    {   head = head->next;  
        if( head->coef == 0 )  
            continue;
            judge=true;
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    if (judge==false)
    {
        printf("<0,0>,");  
    }
    
    printf("\n");  
}  
void multiplication( NODE * head1, NODE * head2, NODE * head3 )  
{   NODE * p1, * p2, * p3, * q;  
    p1 = head1->next;  
    while ( p1 != NULL )  
    {   p2 = head2->next; 
         p3 = head3;  
        while ( p2 != NULL )  
        {   
            while ( p3->next != NULL && p3->next->exp < p1->exp + p2->exp )  
                p3 = p3->next;  
            if ( p3->next != NULL && p3->next->exp == p1->exp + p2->exp )  
            {   p3->next->coef += p1->coef * p2->coef;  
                if ( p3->next->coef == 0 )  
                {   q = p3->next;  
                    p3->next = q->next;  
                    free(q);  
                }  
            }  
            else  
            {   q = ( NODE * ) malloc( sizeof(NODE) );  
                q->coef = p1->coef * p2->coef;  
                q->exp = p1->exp + p2->exp;  
                q->next = p3->next;  
                p3->next = q;  
            }  
            p2 = p2->next;  
        }  
        p1 = p1->next;  
    }  
}
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  