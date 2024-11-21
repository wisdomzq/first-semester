#include<iostream>
#include<queue>
using namespace std;
int Map[1005][1005];
int Turn[1005][1005];
int Dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//右左下上
typedef struct node
{
    int x,y;
    int dir;//方向
    int step;//转向次数
}Node;
int n,m,sx,sy,ex,ey;
bool flag;
void bfs()
{
   Node start;
   queue<Node> q;
   flag=false;
    for(int i=0;i<4;i++)
    {
        start.x=sx+Dir[i][0];
        start.y=sy+Dir[i][1];
        start.dir=i;
        start.step=1;
        Turn[start.x][start.y]=start.step;
        q.push(start);
    }
    while(!q.empty())
    {
        Node now=q.front();
        q.pop();
        if(now.x==ex&&now.y==ey)
        {
            flag=true;
            return;
        }
        for(int i=0;i<4;i++)//对当前的点遍历四个方向
        {
            Node next;
            next.x=now.x+Dir[i][0];
            next.y=now.y+Dir[i][1];
            next.dir=i;
            if(next.dir!=now.dir) next.step=now.step+1; //如果方向不同，转向次数加一
            else next.step=now.step;
            if(next.step>3||next.x<0||next.x>n-1||next.y<0||next.y>m-1) continue;
            if(Map[next.x][next.y]!=0&&Map[next.x][next.y]!=Map[ex][ey]) continue;
            if(Turn[next.x][next.y]==0||Turn[next.x][next.y]>=next.step)
            {
                Turn[next.x][next.y]=next.step;
                q.push(next);
            }
        }
    }
   
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>Map[i][j];
        }
    }
    cin>>sx>>sy>>ex>>ey;
    bfs();
    if(flag) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
}