#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char s[105];
int degreecount[100],maxdegree;
int len;
typedef struct Tree
{
    char data;
    //一个树有多个子节点
    vector<Tree*> child;
}tree;
tree* BuildTree(tree *&t,int &i)
{
     if(i>=len)    return NULL;
     if(s[i]=='(')
     {
          i++;
          if(i>=len||s[i]==')')    return NULL;
          char ch=s[i];
          t=new tree;
          t->data=ch;
          i++;
          while(s[i]!=')')
          {
              if(s[i]==',')    i++;
              tree *child = new tree;
              BuildTree(child,i);
              if(child!=NULL)
              {
                  t->child.push_back(child);
              }
          }
          if(s[i]==')')
          {
              i++;
          }
        return t;
     }
     return NULL;
}
void PrintTree(tree *t,int depth)
{
    if(t!=NULL)
    {
        for(int i=0;i<depth*4;i++)
        {
            cout<<" ";
        }
        cout<<t->data<<endl;
        for(int i=0;i<t->child.size();i++)
        {
            PrintTree(t->child[i],depth+1);
        }
    }
}
void ComputeDegree(tree *t)
{
    if(t==NULL)    return;
    if(t!=NULL)
    {
        int degree=t->child.size();
        degreecount[degree]++;
        maxdegree=max(maxdegree,degree);
        for(int i=0;i<t->child.size();i++)
        {
            ComputeDegree(t->child[i]);
        }
    }
}
int main()
{
    cin>>s;
    len=strlen(s);
    tree *t;
    int i=0;
    if(len==2)
    {
        cout<<"Degree of tree: 0"<<endl;
        cout<<"Number of nodes of degree 0: 0"<<endl;
    }
    BuildTree(t,i);
    PrintTree(t,0);
    ComputeDegree(t);
    cout<<"Degree of tree: "<<maxdegree<<endl;
    for(int i=0;i<=maxdegree;i++)
    {
        cout<<"Number of nodes of degree "<<i<<": "<<degreecount[i]<<endl;
    }

    
}