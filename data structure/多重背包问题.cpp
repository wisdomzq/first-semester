#include<iostream>
using namespace std;
int v[105],p[105],k[105],dp[105][105];
int N,V;
int main()
{
    cin>>N>>V;
    for(int i=1;i<=N;i++)
        cin>>v[i]>>p[i]>>k[i];
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=V;j++)
        {
            dp[i][j]=dp[i-1][j];
            for(int l=0;l<=k[i];l++)
            if(j>=v[i]*l)
                dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]*l]+p[i]*l);
          
        }
    }
    cout<<dp[N][V]<<endl;
}