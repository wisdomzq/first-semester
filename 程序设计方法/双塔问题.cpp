#include<iostream>
#include<cstring>
using namespace std;
int a[105],b[105],f[105][105],m,n,ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(1)
    {
        cin>>m>>n;
        ans++;
        if(m==0&&n==0)break;
        for(int i=1;i<=m;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(a[i]==b[j])f[i][j]=f[i-1][j-1]+1;
                
            }
        }
        cout<<"Twin Towers #"<<ans<<endl;
       cout<<"Number of Tiles : "<<f[m][n]<<endl;
       memset(f,0,sizeof(f));
    }
}