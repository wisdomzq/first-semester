#include<iostream>
#include<cstring>
using namespace std;
int col[1000005],hei[1000005],visit[1000005];
int stk[1000005],mark[1000005],top,count;
int main()
{
    int T,n;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>col[i];
        for(int i=1;i<=n;i++)cin>>hei[i];
        top=0,count=0;
        memset(stk,0,sizeof(stk));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
        {
            while(top&&stk[top]<=hei[i])
            {
                visit[mark[top]]--; 
                 if(visit[mark[top]]==0) count--;
                top--;
               
            }
            stk[++top]=hei[i];
            mark[top]=col[i];
            visit[col[i]]++;
            
            if(visit[col[i]]==1) count++;
        cout<<count;
        if(i!=n) cout << " ";
       }
    cout<<endl;
    }
}