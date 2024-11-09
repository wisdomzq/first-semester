#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char s[1005];
int degreecount[100],maxdegree;
int len;
typedef struct Tree
{
    char data;
    //一个树有多个子节点
    vector<Tree*> child;
    int height;
}tree;
typedef struct Node
{
    int height,num;
}node;
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
        cout<<t->data<<endl;
        for(int i=0;i<t->child.size();i++)
        {
            PrintTree(t->child[i],depth+1);
        }
    }
}
void Height(tree *t)
{
    //计算树每个节点的高度
    if(t->child.size()==0)
    {
        t->height=1;
        return;
    }
    for(int i=0;i<t->child.size();i++)
    {
        Height(t->child[i]);
    }
    int maxheight=0;
    for(int i=0;i<t->child.size();i++)
    {
        maxheight=max(maxheight,t->child[i]->height);
    }
    t->height=maxheight+1;

}
tree* Search(tree *t,char ch)
{
    if(t->data==ch)
    {
        return t;
    }
    for(int i=0;i<t->child.size();i++)
    {
        tree *p=Search(t->child[i],ch);
        if(p!=NULL)
        {
            return p;
        }
    }
    return NULL;
}
bool Win(tree *t)
{
    if(t->child.size()==0)
    {
        return true;
    }
    for(int i=0;i<t->child.size();i++)
    {
        if(Win(t->child[i])==true)
        {
            return false;
        }
    }
    return true;
}
tree* Judge(tree *t)
{
    int maxheight=0,mark=0,minheight=100;
    node l[205];
    for(int i=0;i<t->child.size();i++)
    {
        maxheight=max(maxheight,t->child[i]->height);
        if(Win(t->child[i])==true)
        {
           l[++mark].height=t->child[i]->height;
           l[mark].num=i;
           minheight=min(minheight,t->child[i]->height);
        }
    }
    //若存在多个可以确保取胜的孩子结点，则选择其中高度最小的结点作为下一步（若有多个选择，则选最左边的结点）；
    for(int i=1;i<=mark;i++)
    {
        if(l[i].height==minheight)
        {
            return t->child[l[i].num];
        }
    }
    //若不存在可以确保取胜的一个孩子结点，则选择高度最大的孩子结点作为下一步（若有多个选择，则选最左边的结点）；
    for(int i=0;i<t->child.size();i++)
    {
        if(t->child[i]->height==maxheight)
        {
            
            return t->child[i];
        }
    }
}
int main()
{
    cin>>s;
    len=strlen(s);
    tree *t;
    int i=0;
    BuildTree(t,i);
    Height(t);
    PrintTree(t,0);
    while(1)
    {
        cout<<"Who play first(0: computer; 1: player )?"<<endl;
        int choice;
        cin>>choice;
        if(choice==0)
        {
            //computer play first
            //computer play
            //player play
            bool flag=false;
            tree *q=Judge(t),*p;
            cout<<"computer: "<<q->data<<endl;
            char ch;
            while(1)
            {
                        cout<<"player:"<<endl;
                        cin>>ch;
                        p=Search(q,ch);
                        if(p!=NULL&&p!=q)break;
                        else
                        cout<<"illegal move."<<endl;
            }
            if(p->child.size()==0)
            {
                cout<<"Congratulate, you win."<<endl;
                cout<<"Continue(y/n)?"<<endl;
                flag=true;
            }
            if(flag==false)
            while(1)
            {
                //电脑决策下一个节点
                tree *q=Judge(p);
                cout<<"computer: "<<q->data<<endl;
                if(q->child.size()==0)
                {
                    cout<<"Sorry, you lost."<<endl;
                    cout<<"Continue(y/n)?"<<endl;
                    flag=true;
                }
                else{
                     while(1)
                    {
                        cout<<"player:"<<endl;
                        cin>>ch;
                        p=Search(q,ch);
                        if(p!=NULL&&p!=q)break;
                        else
                        cout<<"illegal move."<<endl;
                    }
                    if(p->child.size()==0)
                    {
                        cout<<"Congratulate, you win."<<endl;
                        cout<<"Continue(y/n)?"<<endl;
                        flag=true;
                    }
                }
                if(flag==true)break;
            }
        }
        else
        {
            //player play first
            tree *p;
            char ch;
            while(1)
            {
            cout<<"player:"<<endl;
            //player play
            cin>>ch;
            //computer play
            p=Search(t,ch);
            if(p->height==1||p==NULL)//第一步不能选择叶子节点
            {
                cout<<"illegal move."<<endl;
            }
            else break;
            }
            bool flag=false;
            while(1)
            {
                //电脑决策下一个节点
                tree *q=Judge(p);
                cout<<"computer: "<<q->data<<endl;
                if(q->child.size()==0)
                {
                    cout<<"Sorry, you lost."<<endl;
                    cout<<"Continue(y/n)?"<<endl;
                    flag=true;
                }
                else{
                    while(1)
                    {
                        cout<<"player:"<<endl;
                        cin>>ch;
                        p=Search(q,ch);
                        if(p!=NULL&&p!=q)break;
                        else
                        cout<<"illegal move."<<endl;
                    }
                    if(p->child.size()==0)
                    {
                        cout<<"Congratulate, you win."<<endl;
                        cout<<"Continue(y/n)?"<<endl;
                        flag=true;
                    }
                }
                if(flag==true)break;
            }
        }
        char k;
        cin>>k;
        if(k=='n')break;
    }
}