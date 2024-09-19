#include<iostream>
#include<vector>
#include<string>
using namespace std;
int m,n;
char a[20][20];
vector<vector<int>> light;
// 方向数组，表示上下左右四个方向
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
// 翻转灯的状态
void turn(int x, int y,vector<vector<int>> &g)
{
    for(int i=0;i<5;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<m&&ny>=0&&ny<n)
            g[nx][ny]=1-g[nx][ny];
    }
}
int main()
{
    cin>>m>>n;
    light.resize(m, vector<int>(n));
    int minpress=1<<30;
    for(int i=0;i<m;i++)
    {
        string line;
        cin >> line;
        for (int j=0; j<n; j++) {
            light[i][j] = line[j] -'0';
        }
    }
       
    //第二行的状态依赖第一行的操作，枚举第一行的状态
    for(int i=0;i<(1<<n);i++)
    {
         int press=0;
         vector<vector<int>> t=light;
        //根据第一行的状态按按钮，遍历所有按按钮的情况
        for(int j=0;j<n;j++)
         {
            if(i&(1<<j))
            {
                press++;
                turn(0,j,t);
            }
         }
         //从第二行开始，根据上一行的状态按按钮
            for(int j=1;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(t[j-1][k]==1)
                    {
                        press++;
                        turn(j,k,t);
                    }
                }
            }
        //判断最后一行是否全灭
        bool suc=true;
        for(int j=0;j<n;j++)
        {
            if(t[m-1][j]==1)
            {
                suc=false;
                break;
            }
        }
        
        if(suc)
        {
           minpress=min(minpress,press);
        }
    }
    cout<<minpress<<endl;
    
}