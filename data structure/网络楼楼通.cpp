#include<iostream>
using namespace std;
int dis[1005][1005],s[1005],ans;
bool vis[1005];
int n,m,x,y,w;
void prim()
{
    s[1]=0;
    vis[1]=1;
    for(int i=2;i<=n;i++)
        s[i]=min(s[i],dis[1][i]);//将1号点到其他点的距离赋给s数组
    for(int i=2;i<=n;i++)
    {
        int minn=1e9;
        int k=-1;////接下来去寻找离集合S最近的点加入到集合中，用t记录这个点的下标
        for(int j=2;j<=n;j++)
            if(!vis[j]&&s[j]<minn)//如果这个点没有加入集合S，而且这个点到集合的距离小于temp就将下标赋给t
                minn=s[j],k=j;
        if(k==-1)
        {
            ans=1e9;
            return;
        }
        vis[k]=1;
        ans+=s[k];
        for(int j=2;j<=n;j++)
                s[j]=min(s[j],dis[k][j]);//用新加入的点更新dist[]

    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1e9,s[i]=1e9;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        dis[x][y]=dis[y][x]=w;
    }
    prim();
    if(ans==1e9)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
}