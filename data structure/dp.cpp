#include<iostream>
using namespace std;
int dp[101];
int main()
{
    int n,tot;
    cin>>n;
    tot=n*(1+n)/2;
    if(tot&1)cout<<0<<endl;
    else
    {
        tot/=2;
        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=tot;j>=i;j--)
                dp[j]+=dp[j-i];
                cout<<dp[tot]/2<<endl;
    }
}