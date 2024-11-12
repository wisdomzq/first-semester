#include<iostream>
using namespace std;
int P[15][15],Q[15][15],n;
int val[15][15],maxBoy[15];
int ans=0,sum=0;
bool vis[15];
//该方法遍历所有的排列情况，总共有n!种情况，tle
/*
void swap(int &a,int &b)
{
    int temp;
    temp=a,a=b,b=temp;
}
int Calculate(int p[])
{
    int sum=0;
    for(int i=0;i<n;i++)
            sum+=P[i][p[i]]*Q[p[i]][i];
    return sum;
}
void Pram(int p[],int l,int r)
{
    if(l==r)
    {
        ans=max(ans,Calculate(p));
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swap(p[l],p[i]);
        Pram(p,l+1,r);
        swap(p[l],p[i]);
    }
}
*/
void dfs(int x)
{
    if(x>=n)
    {
        ans=max(ans,sum);
        return;
    }
    int cnt=0;
    for(int i=x;i<n;i++) cnt+=maxBoy[i];
    //剪枝，如果当前的sum+cnt小于ans，那么后面的情况就不用再考虑了
    if(sum+cnt<=ans) return;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            sum+=val[x][i];
            dfs(x+1);
            sum-=val[x][i];
            vis[i]=false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>P[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>Q[i][j];
    for(int i=0;i<n;i++)  
     for(int j=0;j<n;j++)
     {
         val[i][j]=P[i][j]*Q[j][i];
         // //记录每个男生匹配后可达到的最大双方竞赛优势，用于后面的剪枝
         maxBoy[i]=max(maxBoy[i],val[i][j]);
     }
     dfs(0);
    cout<<ans<<endl;
}