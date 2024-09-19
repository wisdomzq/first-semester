#include<iostream>
#include<algorithm>
using namespace std;
struct task
{
    int be,en;
}t[300005];
bool cmp(task a,task b)
{
    return a.en<b.en;
}
int main()
{
    int n,ans=0,k=1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>t[i].be>>t[i].en;
    sort(t+1,t+n+1,cmp);
    while(k<n)
    {
        ans++;
        int x=t[k].en;
        while(t[k].be<x&&k<=n)k++;
        if(k==n)
        {
           ans++; break;
        }
        if(k>n) break;
    }
    
    cout<<ans<<endl;
}
