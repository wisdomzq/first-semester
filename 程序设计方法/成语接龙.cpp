#include<iostream>
#include<vector>
using namespace std;
int be[300005],en[300005];
bool visit[300005];
int n,l,r,minn=10000000;
struct node{
    int num,mark;
};
vector<node> q[300005];

void dfs(int x,int y,int mark)
{
    if(visit[mark])return;
    visit[mark]=1;
    if(x==r)
    {
        minn=min(minn,y+1);
        return;
    }
    for(int i=0;i<q[x].size();i++)
    {
        
        if(q[x][i].num==r)
        {

            minn=min(minn,y+2); 
            return;
        }
        else dfs(q[x][i].num,y+1,q[x][i].mark);
    }
  
}
int main()
{
    cin>>n;
    int a1,a2,a3,a4,b1,b2,b3,b4;
    for(int i=1;i<=n;i++)cin>>be[i]>>l>>r>>en[i];
    cin>>a1>>a2>>a3>>a4>>b1>>b2>>b3>>b4;
    if(a1==b1&&a2==b2&&a3==b3&&a4==b4)cout<<1<<endl;
    else{
        if(a4==b1)cout<<2<<endl;
        else{
             l=a4,r=b1;
             
        for(int i=1;i<=n;i++)
        {
           node tmp;
           tmp.num=en[i];
           tmp.mark=i;
            q[be[i]].push_back(tmp);
        }
        dfs(a4,1,0);
        if(minn==10000000)cout<<-1<<endl;
        else
        cout<<minn<<endl;
        }
       
    }
}
