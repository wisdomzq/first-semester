#include<iostream>
using namespace std;
int v[1005],p[1005],dp[1005][1005];
int N,V;
int main()
{
    cin>>N>>V;
    for(int i=1;i<=N;i++)
        cin>>v[i]>>p[i];
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=V;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=v[i])
                dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+p[i]);
        }
    }
    cout<<dp[N][V]<<endl;
}