#include<iostream>
#include<queue>
using namespace std;
struct node{
    int dis;
    int end;
};
struct Node{
    int end,dis;
    friend bool operator <(Node a,Node b){  //重载运算符,使得优先队列按照dis从小到大排序
        return a.dis>b.dis;
    }
};
int n,m;
char be;
int dis[1005];
bool vis[1005];
vector<node> G[1005];
void Dij()
{
    priority_queue<Node> q;
    q.push({be-'a',0});
    while(!q.empty())
    {
        int now=q.top().end;
        q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=0;i<G[now].size();i++)
        {
            int next=G[now][i].end;
            int w=G[now][i].dis;
            if(dis[next]>dis[now]+w)
            {
                dis[next]=dis[now]+w;
                if(!vis[next])
                q.push({next,dis[next]});
            }
        }
    }
}
int main()
{
    char op;
    char l,r;
    int w;
    cin>>n>>op>>m>>op>>be;
    for(int i=0;i<n;i++)
    {
        dis[i]=0x3f3f3f3f;
    }
    dis[be-'a']=0;
    for(int i=1;i<=m;i++)
    {
       cin>>op>>l>>op>>r>>op>>w>>op;
       G[l-'a'].push_back({w,r-'a'});
    }
    Dij();
    for(int i=0;i<n;i++)
    {
      
        cout<<char(i+'a')<<":"<<dis[i]<<endl;
    }
}