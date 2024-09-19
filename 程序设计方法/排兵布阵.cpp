#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long x[100005],y[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    long long ans=0;
    for(int i=1;i<=n;i++)x[i]-=i;
     sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)ans+=abs(x[i]-x[(n+1)/2])+abs(y[i]-y[(n+1)/2]);
    cout<<ans<<endl;
    return 0;
}