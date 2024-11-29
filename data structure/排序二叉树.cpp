#include<iostream>
using namespace std;
struct BiTNode
{
    int data;
    BiTNode *lchild,*rchild;
};
int num;
int cnt;
// 凹入表示打印二叉树
void PrintIndented(BiTNode* T, int depth) {
    if (T == NULL) return;
    PrintIndented(T->rchild, depth + 1);
    for (int i = 0; i < depth; ++i) cout << "    ";  // 每一级缩进4个空格
    cout << T->data << endl;
    PrintIndented(T->lchild, depth + 1);
}
// 中序遍历二叉树
void InOrderTraverse(BiTNode* T) {
    if (T == NULL) return;
    InOrderTraverse(T->rchild);
    cout << T->data ;
    if(cnt>2)
    {
        cout<<" ";
        cnt--;
    }
    InOrderTraverse(T->lchild);
}
int main()
{
    BiTNode *T;
    T=NULL;
    while(cin>>num)
    {
        cnt++;
        if(num==0) break;
        BiTNode *p=new BiTNode;
        p->data=num;
        p->lchild=NULL;
        p->rchild=NULL;
        if(T==NULL)
        {
            T=p;
        }
        else
        {
            BiTNode *q=T;
            BiTNode *r;
            while(q)
            {
                r=q;
                if(num>q->data)
                {
                    q=q->lchild;
                }
                else
                {
                    q=q->rchild;
                }
            }
            if(num>r->data)
            {
                r->lchild=p;
            }
            else
            {
                r->rchild=p;
            }
        }
        
    }
    PrintIndented(T,0);
    cout<<endl;
    cout<<" ";
    InOrderTraverse(T);
    cout<<1;
    cout << endl;
}