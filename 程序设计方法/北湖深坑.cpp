#include<iostream>
using namespace std;
#define ull unsigned long long
ull a[100005],n,rmax[100005],lmax[100005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ull lmaxx=0,rmaxx=0,ans=0;
        for(int i=1;i<=n;i++)cin>>a[i],lmax[i]=a[i],rmax[i]=a[i];
        for(int i=1;i<=n;i++)
        {
            lmaxx=max(lmax[i],lmaxx);
            lmax[i]=max(lmaxx,lmax[i]);
        }
        for(int i=n;i>=1;i--)
        {
            rmaxx=max(rmax[i],rmaxx);
            rmax[i]=max(rmaxx,rmax[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==rmax[i]||a[i]==lmax[i])continue;
            else
            ans+=(min(rmax[i],lmax[i])-a[i]);
        }
        cout<<ans<<endl;
    }
}