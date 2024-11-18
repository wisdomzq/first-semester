#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> G[35],component[35];
bool vis[35];
int n,num;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x]=1;
    num++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        component[num].push_back(u);
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    
    cin>>n;
    int x,y;
    while(cin>>x)
    {
        if(x==-1) break;
        cin>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        sort(G[i].begin(),G[i].end());
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        bfs(i);
    }
   
    // sort(component+1,component+num+1);
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<component[i].size();j++)
        {
            cout<<component[i][j];
            if(j!=component[i].size()-1) cout<<"-";
        }
        cout<<endl;
    }
}