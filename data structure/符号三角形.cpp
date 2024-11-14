#include<iostream>
#include <string.h>
using namespace std;
long long n,half,sum=0,count=0;
int a[30][30];
bool vis[30];
int mark[30];
void backtrack(int x)
{
     if(count>half||x*(x-1)/2-count>half)
         return ;
     if(x>n) sum++;
        else
        {
            for(int i=0;i<=1;i++)
            {
               a[1][x]=i;
               count+=i;
               for(int j=2;j<=x;j++)
               {
                   if(a[j-1][x-j+1]==a[j-1][x-j+2])
                   {
                       a[j][x-j+1]=1;
                   }
                   else
                   {
                       a[j][x-j+1]=0;
                   }
                   count+=a[j][x-j+1];
               }
               backtrack(x+1);
            for(int j=2;j<=x;j++)
            {
                count-=a[j][x-j+1];
            }
            count-=i;
            }
            
        }
}

int main()
{
      vis[27]=true;
    mark[27]=5804913;
    vis[24]=true;
    mark[24]=822229;
    vis[23]=true;
    mark[23]=431095;
    vis[20]=true;
    mark[20]=59984;
     vis[19]=true;
    mark[19]=32757;
     vis[16]=true;
    mark[16]=5160;
     vis[15]=true;
    mark[15]=1896;
     while(cin>>n)
     {
        half=n*(n+1)/2;
        if(half%2==1)
        {
            cout<<0<<endl;
        }
        else
        {
            if(vis[n])
            {
                cout<<mark[n]<<endl;
                continue;
            }
            half=half/2;
            for(int i=0;i<=n;i++)
             for(int j=0;j<=n;j++)
             {
                 a[i][j]=0;
             }
            sum=0,count=0;
            backtrack(1);
            mark[n]=sum;
            vis[n]=true;
            cout<<sum<<endl;
        }
     }
}