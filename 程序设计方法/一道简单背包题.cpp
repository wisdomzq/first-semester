#include<iostream>
using namespace std;
int n,v,a[2005];
long long f[2005][2005];
int main()
{
    cin>>n>>v;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[0][0]=1; //f[i][j]表示前i个物品中余数为j的方案个数
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v;j++)  f[i][j]=f[i-1][j];//先预处理，不选第i个物品
        for(int j=0;j<v;j++)  f[i][(j+a[i]%v)%v]+=f[i-1][j],f[i][(j+a[i]%v)%v]%=10000000;//选第i个物品
        
    }
    cout<<(f[n][0]-1)%10000000<<endl;
}