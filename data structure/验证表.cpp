#include<iostream>
#include<string>
using namespace std;
typedef struct node
{
    int num;
    string name;
    node *next;
}NODE,*PNODE;
void input(PNODE head)
{
    PNODE p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    PNODE q=new NODE;
    cin>>q->num>>q->name;
    q->next=NULL;
    p->next=q;
}
void check(PNODE head,PNODE head1)
{
   
    PNODE q=head1->next;
    bool flag=false,flag1=false;
    while(q!=NULL)
    {
       flag1=false;
        PNODE p=head->next;
        while(p!=NULL)
        {
            if(p->num==q->num)
            {
               if(p->name==q->name)
               {
                 flag1=true;
                 p=p->next;
                 continue;
               }
             
              else 
                {
                    flag=true;
                    flag1=true;
                    printf("%8d %s is not in LIST1.\n",q->num,q->name.c_str());
                    p=p->next;
                    continue;
                }
              
            }
            p=p->next;
        }
        if(flag1==false)
        {
            flag=true;
            printf("%8d %s is not in LIST1.\n",q->num,q->name.c_str());
        }
        q=q->next;
    }
    if(flag==false)
    {
        cout<<"the records of LIST2 are all in the LIST1."<<endl;
    }
}
int n,m;
int main()
{
    cin>>n;
    NODE *head=new NODE;
    head->next=NULL;
    for(int i=1;i<=n;i++)
     input(head);
    PNODE head1;
    head1=new NODE;
    head1->next=NULL;
    cin>>m;
    if(m==0)
    {
        cout<<"the LIST2 is NULL."<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
      input(head1);
    check(head,head1);

}
