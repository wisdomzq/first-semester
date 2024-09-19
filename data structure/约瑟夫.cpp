#include<iostream>
using namespace std;
int n,m,k;
typedef struct node
{
     int num;
     node *next;
     node *pre;
}NODE,*PNODE;
bool visit[1000];
void Build(PNODE head)//双向链表
{
   int i=1;
   PNODE q;
   q=head;
    while(i<n)
    {
        PNODE p;
        p=new NODE;
        p->num=i+1;
        p->next=NULL;
        head->next=p;
        p->pre=head;
        head=p;
        i++;
        if(i==n)
        {
            p->next=q;
            q->pre=p;
        }
    }
}
void Output(PNODE head)
{
    int i=1,num=0;
    while(i<k)
    {
        head=head->next;
        i++;
    }
    PNODE head1,head2;
    head1=head2=head;
    i=1;
    while(num<n-1)
    {
        PNODE p,q;
        p=head1;//head1逆时针
        q=head2;//head2顺时针
        while(i<m)
        {
            q=q->next;
            p=p->pre;
            i++;
        }
        if(p==q)
        {
            cout<<p->num<<",";
            visit[p->num]=true;
            num++;
            PNODE del=p->next;
            PNODE dnext=p->pre;
            del->pre=dnext;
            dnext->next=del;
            delete p;
            head1=dnext;
            head2=del;
        }
        else
        {
            cout<<q->num<<"-"<<p->num<<",";
            visit[q->num]=true;
            visit[p->num]=true;
            num+=2;
            PNODE del=p->next,del1=q->pre;//p逆时针，q顺时针
            PNODE dnext=p->pre,dnext1=q->next;
            del->pre=dnext;
            dnext->next=del;
            del1->next=dnext1;
            dnext1->pre=del1;
            delete p;
            delete q;
            head1=dnext;
            head2=dnext1;
        }
        i=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        cout<<i<<",";
    }
    cout<<endl;
    
}
int main()
{
    char ch;
    cin>>n>>ch>>k>>ch>>m;
    if(!n||!m||!k)
    {
        cout<<"n,m,k must bigger than 0."<<endl;
        return 0;
    }
    else{
        if(k>n)
        cout<<"k should not bigger than n."<<endl;
        else
        {
            PNODE head;
            head=new NODE;
            head->num=1;
            head->next=NULL;
            Build(head);
            Output(head);
        }

    }
}
