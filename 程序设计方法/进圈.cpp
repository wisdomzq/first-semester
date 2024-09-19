#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
char maze[1001][1001];
bool visit[1001][1001];
int dis[1001][1001];
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
            for(int j=1;j<=k;j++)
            {
            int x=now.x+j*dir[i][0];
            int y=now.y+j*dir[i][1];
            int t=now.time+1;
            
             
          
             if (x < 0 || y < 0 || x> n || y > m || maze[x][y] == '#') {
                    break;  // 遇到障碍或越界，停止向这个方向扩展
                } 
                 if(judge(x,y)&&!visit[x][y])
            {
               visit[x][y]=true;
               dis[x][y]=t;
               q.push({x,y,t});
            }
            }
           
        }
    }
    return -1;
}
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        int startx,starty,endx,endy;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
                maze[i][j+1]=s[j];     
        }
        cin>>startx>>starty>>endx>>endy;
        memset(visit,false,sizeof(visit));
        cout<<bfs(startx,starty,endx,endy)<<endl;
}
