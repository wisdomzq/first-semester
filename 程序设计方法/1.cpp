#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dist[1000005];
bool mark[100005];
struct node{
    int end,dis;
};
struct Node{
    int end,dis;
    bool operator <( const Node &x )const
    {
        return x.dis<dis;
    }
};
vector<node> edge[100005];
int n,m,s,u,v,w,T,l,r;
void Dij()
{
    priority_queue<Node> q;
    Node tmp;
    tmp.end=s;
    tmp.dis=0;
    q.push(tmp);
    while(!q.empty())
    {
        int u1=q.top().end;
        q.pop();
        if(mark[u1])continue;
        mark[u1]=1;
        for(int i=0;i<edge[u1].size();i++)
        {
            int v1=edge[u1][i].end,l=edge[u1][i].dis;
            if(!mark[v1]&&dist[v1]>dist[u1]+l)
            {
                dist[v1]=dist[u1]+l;
                tmp.end=v1;
                tmp.dis=dist[v1];
                q.push(tmp);
            }
        }
    }
}
int main()
{
   
    
    cin>>n;
    int a1,a2,a3,a4,b1,b2,b3,b4;
    for(int i=1;i<=1000004;i++)dist[i]=0x7fffffff;
    
    
    node tmp;
    for(int i=1;i<=n;i++)
    {
       cin>>u>>l>>r>>v;
        tmp.end=v;
        tmp.dis=1;
        edge[u].push_back(tmp);  
    }
     cin>>a1>>a2>>a3>>a4>>b1>>b2>>b3>>b4;
     s=a4;
     dist[s]=0;
     if(a1==b1&&a2==b2&&a3==b3&&a4==b4)cout<<1<<endl;
     else{
        Dij();
        if(dist[b1]==0x7fffffff)cout<<-1<<endl;
        else
        cout<<dist[b1]+2<<endl;
     }
    
}