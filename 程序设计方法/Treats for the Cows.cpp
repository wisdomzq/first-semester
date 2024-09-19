#include<iostream>
using namespace std;
int a[2005];
long long f[2005][2005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],f[i][i]=a[i]*n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            f[j][i]=max(f[j+1][i]+a[j]*(n-i+j),f[j][i-1]+a[i]*(n-i+j));
        }
    }
    cout<<f[1][n]<<endl;

}