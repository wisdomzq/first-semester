#include<iostream>
using namespace std;
typedef struct Bitree
{
    char data;
    int depth;
    Bitree *lchild;
    Bitree *rchild;
}tree;
int maxdepth,leave;
void create(tree *&t,char s[],int &i,int depth)
{
    char ch=s[i++];
    if(ch=='\0')
    {
        return;
    }
    if(ch=='#')
    {
        t=NULL;
    }
    else
    {
        t=new tree;
        t->data=ch;
        t->depth=depth;
        maxdepth=maxdepth>depth?maxdepth:depth;
        create(t->lchild,s,i,depth+1);
        create(t->rchild,s,i,depth+1);
    }
}
void PrintTree(tree *t)
{
    if(t!=NULL)
    {
        for(int i=0;i<t->depth*2;i++)
        {
            cout<<"  ";
        }
        cout<<t->data<<endl;
        PrintTree(t->lchild);
        PrintTree(t->rchild);
    }
}
void PreSequence(tree *t)
{
    if(t!=NULL)
    {
        cout<<t->data;
        PreSequence(t->lchild);
        PreSequence(t->rchild);
    }
}
void InSequence(tree *t)
{
    if(t!=NULL)
    {
        InSequence(t->lchild);
        cout<<t->data;
        InSequence(t->rchild);
    }
}
void PostSequence(tree *t)
{
    if(t!=NULL)
    {
        PostSequence(t->lchild);
        PostSequence(t->rchild);
        cout<<t->data;
    }
}
void CountLeave(tree *t)
{
    if(t!=NULL)
    {
        if(t->lchild==NULL&&t->rchild==NULL)
        {
            leave++;
        }
        CountLeave(t->lchild);
        CountLeave(t->rchild);    
    }
}
void Swap(tree *t)
{
    if(t!=NULL)
    {
        tree *temp=t->lchild;
        t->lchild=t->rchild;
        t->rchild=temp;
        Swap(t->lchild);
        Swap(t->rchild);
    }
}
int main()
{
    char s[100];
    cin>>s;
    tree *t;
    int i=0;
    create(t,s,i,0);
    cout<<"BiTree"<<endl;
    PrintTree(t);
    cout<<"pre_sequence  : ";
    PreSequence(t);
    cout<<endl;
    cout<<"in_sequence   : ";
    InSequence(t);
    cout<<endl;
    cout<<"post_sequence : ";
    PostSequence(t);
    cout<<endl;
    CountLeave(t);
    cout<<"Number of leaf: "<<leave<<endl;
    cout<<"BiTree swapped"<<endl;
    Swap(t);
    PrintTree(t);
     cout<<"pre_sequence  : ";
    PreSequence(t);
    cout<<endl;
    cout<<"in_sequence   : ";
    InSequence(t);
    cout<<endl;
    cout<<"post_sequence : ";
    PostSequence(t);
    cout<<endl;
}