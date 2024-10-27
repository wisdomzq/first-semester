#include<iostream>
using namespace std;
typedef struct Node{
    int orderbid;
    int stockid;
    float price;
    int quantity;
    char type;
    struct Node *next;
} NODE;
NODE *head1, *p, *head2;//head1 is for buy, head2 is for sell
void InitBuy()
{
    head1 = new NODE;
    head1->next = NULL;
    head1->orderbid = -1;
    head1->price = -1.0;
    head1->quantity = -1;
    head1->stockid = -1;
    head1->type = 'x';
    head1->next = NULL;
}
void InitSell()
{
    head2 = new NODE;
    head2->next = NULL;
    head2->orderbid = -1;
    head2->price = -1.0;
    head2->quantity = -1;
    head2->stockid = -1;
    head2->type = 'x';
    head2->next = NULL;
}
void SaveBuy(NODE *p)
{
    NODE *q = head1,*pre;
    int flag1=0;
    while(q->next != NULL)
    {
        pre = q;
        q = q->next;
        if(q->stockid == p->stockid)
        {
            flag1=1;
            while(q!=NULL&&(q->price>=p->price)&&q->stockid==p->stockid)//从大到小存储
            {
                pre = q;
                q = q->next;
            }
            pre->next = p;
            p->next = q;
            break;
        }
    }
    if(flag1==0)
    {
        p->next = head1->next;
        head1->next = p;
    }
    
}
void SaveSell(NODE *p)
{
    NODE *q = head2,*pre;
    int flag1=0;
    while(q->next != NULL)
    {
        pre = q;
        q = q->next;
        if(q->stockid == p->stockid)
        {
            flag1=1;
            while(q!=NULL&&(q->price<=p->price)&&q->stockid==p->stockid)//从小到大存储
            {
                pre = q;
                q = q->next;
            }
            pre->next = p;
            p->next = q;
            break;
        }
    }
    if(flag1==0)
    {
        p->next = head2->next;
        head2->next = p;
    }
}
void DeleteBuy(NODE *p)
{
    NODE *q = head1;
    while(q->next->orderbid != p->orderbid)
        q=q->next;
    q->next = p->next;
    delete p;
}
void DeleteSell(NODE *p)
{
    NODE *q = head2;
    while(q->next->orderbid != p->orderbid)
        q=q->next;
    q->next = p->next;
    delete p;
}
void DeleteQueue()
{
    NODE *q = head1;
    while(q->next)
    {
        q=q->next;
        if(q->quantity==0)DeleteBuy(q);
    }
    q = head2;
    while(q->next)
    {
        q=q->next;
        if(q->quantity==0)DeleteSell(q);
    }
}
int main()
{
    int choice,stockid,quantity,orderbid=  1;
    float price;
    char type;
    InitBuy();
    InitSell();
    while(cin>>choice)
    {
        if(choice==0) break;
        if(choice==1)
        {
            p = new NODE;
            cin>>stockid>>price>>quantity>>type;
            p->orderbid = orderbid;
            p->stockid = stockid;
            p->price = price;
            p->quantity = quantity;
            p->type = type;
            orderbid++;
            printf("orderid: %04d\n",p->orderbid);
            if(type=='b')
            {
                NODE *q = head2;
                while(q->next!=NULL)
                {
                    q=q->next;
                    if(q->stockid!=p->stockid) continue;
                    else{
                        if(q->price<=p->price)
                        {
                            int deal=min(p->quantity,q->quantity);
                            printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",(q->price+p->price)/2,deal,p->orderbid,q->orderbid);
                            p->quantity-=deal;
                            q->quantity-=deal;
                            if(q->quantity==0) DeleteSell(q);
                            if(p->quantity==0) break;
                        }
                        else continue;
                    }

                  
                }
                if(p->quantity!=0) SaveBuy(p);
                else free(p);
            }
            else{
                NODE *q = head1;
                while(q->next!=NULL)
                {
                    q=q->next;
                    if(q->stockid!=p->stockid) continue;
                    else{
                        if(q->price>=p->price)
                        {
                            int deal=min(p->quantity,q->quantity);
                            printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",(q->price+p->price)/2,deal,p->orderbid,q->orderbid);
                            p->quantity-=deal;
                            q->quantity-=deal;
                            if(q->quantity==0) DeleteBuy(q);
                            if(p->quantity==0) break;
                        }
                        else continue;
                    }
                }
                if(p->quantity!=0) SaveSell(p);
                else free(p);
            }
            DeleteQueue();
        }
        if(choice==2)
        {
            int searchstock;
            cin>>searchstock;
            cout<<"buy orders:"<<endl;
            p=head1;
            while(p->next!=NULL)
            {
                p=p->next;
                if(p->stockid==searchstock&&p->quantity!=0)
                    printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderbid,p->stockid,p->price,p->quantity,p->type);
            }
            cout<<"sell orders:"<<endl;
            p=head2;
            while(p->next!=NULL)
            {
                p=p->next;
                if(p->stockid==searchstock&&p->quantity!=0)
                    printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderbid,p->stockid,p->price,p->quantity,p->type);
            }
        }
        if(choice==3)
        {
            int searchorder;
            cin>>searchorder;
            int flag1=0;
            p=head1;
            while(p->next!=NULL)
            {
                p=p->next;
                if(p->orderbid==searchorder)
                {
                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderbid,p->stockid,p->price,p->quantity,p->type); 
                    DeleteBuy(p);
                    flag1=1;
                    break;
                }
            }
            p=head2;
            while(p->next!=NULL)
            {
                p=p->next;
                if(p->orderbid==searchorder)
                {
                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",p->orderbid,p->stockid,p->price,p->quantity,p->type); 
                    DeleteSell(p);
                    flag1=1;
                    break;
                }
            }
            if(flag1==0) printf("not found\n");
        }
    }
}