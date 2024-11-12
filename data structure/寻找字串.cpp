#include<iostream>
#include<string>
using namespace std;
int row[8]={0,1,1,1,0,-1,-1,-1};
int col[8]={-1,-1,0,1,1,1,0,-1};
char a[105][105];
bool vis[105][105]={false};
int n;
void search(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        string s;
        s+=a[x][y];
        for(int j=1;j<4;j++)
        {
            int nx=x+row[i]*j;
            int ny=y+col[i]*j;
            if(nx>=0&&nx<n&&ny>=0&&ny<n)
            {
                s+=a[nx][ny];
            }
            else
            {
                break;
            }
        }
        if(s=="sjjg"||s=="gjjs")
        {
            for(int j=0;j<4;j++)
            {
                vis[x+row[i]*j][y+col[i]*j]=true;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='s')
            {
                search(i,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j])
            {
                cout<<'*';
            }
            else
            {
                cout<<a[i][j];
            }
        }
        cout<<endl;
    }
}