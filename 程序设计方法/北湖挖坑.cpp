#include<iostream>
using namespace std;
int a[100005];
int main()
{
    int n,h;
    long long ans=0;
    cin>>n>>h;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]=h-a[i];
        a[0]=0;
    for(int i=1;i<=n;i++)
    {
       if(a[i]>a[i-1])ans+=a[i]-a[i-1];
    }
    cout<<ans<<endl;
}