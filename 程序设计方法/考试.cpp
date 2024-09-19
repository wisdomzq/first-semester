#include<iostream>
using namespace std;
int n,m;
struct qu{
    int time,point,score;
}q[26];
long long f[30005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>q[i].time>>q[i].point,q[i].score=q[i].point*q[i].time;
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=q[i].time;j--)
        {
           f[j]=max(f[j],f[j-q[i].time]+q[i].score);  
        }
    }
    cout<<f[n]<<endl;
}