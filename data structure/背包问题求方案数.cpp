#include<iostream>
#include<cstring>
#define mod 1000000007
using namespace std;
long long v[1005],p[1005],dp[1005],cnt[1005];//dp记录容积为i时最大价值，cnt记录最大价值的方案数
int N,V;
int main()
{
    cin>>N>>V; 
    for(int i=1;i<=1004;i++)
        cnt[i]=1;
    for(int i=1;i<=N;i++)
        cin>>v[i]>>p[i];
   
    for(int i=1;i<=N;i++)
    {
        for(int j=V;j>=v[i];j--)
        {
           if(dp[j-v[i]]+p[i]>dp[j])
           {
                dp[j]=dp[j-v[i]]+p[i];
                cnt[j]=cnt[j-v[i]];
                cnt[j]%=mod;
              }
              else if(dp[j-v[i]]+p[i]==dp[j])
              {
                cnt[j]+=cnt[j-v[i]];
                cnt[j]%=mod;
              }
        }
    }
    cout<<cnt[V]%mod<<endl;
}
