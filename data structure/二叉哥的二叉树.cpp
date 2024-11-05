#include<iostream>
#include<cmath>
using namespace std;
int T;
int n,m,num;
int count(int n,int m)
{
    if(n<=m)//一层只放一个都不够
    {
        num+=0;
        return num;
    }
    else
    if(n==m+1)//一层只放一个刚好够
    {
        num+=1;
        return num;
    }
    else{
    n=n-m-1;
    num+=1;
    int layer=1;
    if(n==0||layer>m)
    return num;
    int full;
    full=pow(2,layer)-1;
    while(n>full)//如果n大于这一层的节点数,可以全部放进去
    {
        num+=pow(2,layer-1);
        n-=full;
        layer++;
        full=pow(2,layer)-1;
        if(layer>m) return num;
    }
    if(n-full==0)
    {
        num+=pow(2,layer-1);
        return num;
    }
    return count(n,layer-1);//新的一层不够放，当成新的情况递归
    }
   

}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        num=0;
        cout<<count(n,m)<<endl;
    }
}
