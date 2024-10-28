#include<iostream>
using namespace std;
typedef struct
{
    int i,j;//行号，列号
    int e;//元素值
}Triple;
typedef struct
{
    int Rows,Cols,Num;//行数，列数，非零元个数
    Triple data[105];//非零元三元组表
}SparseMatrix;
void FastTraspose(SparseMatrix s,SparseMatrix &t)
{
   t.Rows=s.Cols,t.Cols=s.Rows,t.Num=s.Num;
   int num[105],cpot[105];
   for(int i=1;i<=s.Cols;i++) num[i]=0;
    for(int i=1;i<=s.Num;i++) num[s.data[i].j]++;//求出每一列的非零元个数
    cpot[1]=1;
    for(int i=2;i<=s.Cols;i++) cpot[i]=cpot[i-1]+num[i-1];//求出每一列的第一个非零元在t.data中的位置
    for(int i=1;i<=s.Num;i++)
    {
       int col=s.data[i].j;
       int pos=cpot[col];
       t.data[pos].i=s.data[i].j;
       t.data[pos].j=s.data[i].i;
       t.data[pos].e=s.data[i].e;
       cpot[col]++;
    }
}
int main()
{
    SparseMatrix A,B,B_T;
    cin>>A.Rows>>A.Cols>>A.Num;
    for(int i=1;i<=A.Num;i++)
    {
        cin>>A.data[i].i>>A.data[i].j>>A.data[i].e;
    }
    cin>>B.Rows>>B.Cols>>B.Num;
    for(int i=1;i<=B.Num;i++)
    {
        cin>>B.data[i].i>>B.data[i].j>>B.data[i].e;
    }
    cout<<A.Rows<<endl;
    cout<<B.Cols<<endl;//矩阵A*B的行数和列数
    FastTraspose(B,B_T);
    Triple C[205];
    int k=0;
    for(int i=1;i<=A.Rows;i++)
    {
       for(int j=1;j<=B_T.Rows;j++)
       {
           int sum=0;
           for(int k=1;k<=A.Num;k++)
           {
               if(A.data[k].i==i)
               {
                   for(int l=1;l<=B_T.Num;l++)
                   {
                       if(B_T.data[l].i==j&&A.data[k].j==B_T.data[l].j)
                       {
                           sum+=A.data[k].e*B_T.data[l].e;
                       }
                    
                   }
               }
           }
           if(sum!=0) C[++k].i=i,C[k].j=j,C[k].e=sum;
          
       }
    }
    cout<<k<<endl;
    if(k==0) return 0;
    for(int i=1;i<=k;i++)
    {
        cout<<C[i].i<<","<<C[i].j<<","<<C[i].e<<endl;
    }
}