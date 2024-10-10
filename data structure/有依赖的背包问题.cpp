#include<iostream>
using namespace std;
int N,V,root;
int v[105],p[105],jie[105],dp[1005][1005],a[105][105],b[105];
//a[i][j]表示以i为头结点有j个子节点，a[i][j]则存的是下标，b[i]表示以i为根结点有b[i]个子节点
//dp[i][j]表示以i为根节点，背包容量为j所获得的最大价值
void add(int a1,int b1)//把子节点b加到父节点a下面
{
    
    a[a1][b[a1]]=b1;b[a1]++;
}

void dfs(int t)//此时t为父节点，要想选下面的，前提就是把父节点选了，所以初始背包容量大于v[t]都初始化w[t]
{
    for(int i=v[t];i<=V;i++)
    {
        dp[t][i]=p[t];
    }
    for(int i=0;i<b[t];i++)
    {
        int son=a[t][i];
        dfs(son);
        for(int j=V;j>=v[t];j--)
        {
            for(int k=0;k<=j-v[t];k++)
            {
                dp[t][j]=max(dp[t][j],dp[t][j-k]+dp[son][k]);
            }
        }
    }
}
int main()
{
    cin>>N>>V;
    for(int i=1;i<=N;i++)
    {
        cin>>v[i]>>p[i]>>jie[i];
        if(jie[i]==-1)
        root=i;
        else
         add(jie[i],i);
        
    }
    dfs(root);
    cout<<dp[root][V]<<endl;
}
