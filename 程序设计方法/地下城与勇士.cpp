#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
char maze[101][101];
bool visit[101][101][51];
int dis[101][101];
int n,m,k;
struct node{
    int x,y,time;
};
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // 四个方向
bool judge(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m&&maze[x][y]!='#')return true;
    return false;
}
int bfs(int x1,int y1,int x2,int y2)
{
    memset(dis,1e9,sizeof(dis));
    queue<node> q;
    q.push({x1,y1,0});
    dis[x1][y1]=0;
    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        if(now.x==x2&&now.y==y2)return now.time;
        for(int i=0;i<4;i++)
        {
            int x=now.x+dir[i][0];
            int y=now.y+dir[i][1];
            int t=now.time+1;
            if(judge(x,y)&&!visit[x][y][t%k])
            {
               if(maze[x][y]=='*'&&t%k!=0)continue;//当前时刻怪物还在
               visit[x][y][t%k]=true;
               dis[x][y]=t;
               q.push({x,y,t});
            }
            
            
        }
    }
    return -1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        int startx,starty,endx,endy;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            
            for(int j=0;j<m;j++)
            {
                maze[i][j+1]=s[j];
                
                if(maze[i][j+1]=='S')startx=i,starty=j+1;
                else if(maze[i][j+1]=='E')endx=i,endy=j+1;
            }
        }
        memset(visit,false,sizeof(visit));
        cout<<bfs(startx,starty,endx,endy)<<endl;
    }
}