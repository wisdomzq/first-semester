#include<iostream>
#include<algorithm>
using namespace std;
struct zheng{
    long long x,y;
}z[200005];
struct fu{
    long long x,y;
}f[200005];
bool zmp(zheng a,zheng b)
{
    return a.x<b.x;
}
bool fmp(fu a,fu b)
{
    return a.x+a.y>b.x+b.y;
}
int main()
{
    long long n,x1,x2,znt=0,fnt=0,cost=0,l=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x1>>x2;
        if(x2>=0)z[++znt].x=x1,z[znt].y=x2;
        else f[++fnt].x=x1,f[fnt].y=x2;
    }
    sort(z+1,z+1+znt,zmp);
    sort(f+1,f+1+fnt,fmp);
    for(int i=1;i<=znt;i++)
    {
          if(l<z[i].x)cost+=z[i].x-l,l=z[i].x;
          l+=z[i].y;
    }
     for(int i=1;i<=fnt;i++)
    {
          if(l<f[i].x)cost+=f[i].x-l,l=f[i].x;
          l+=f[i].y;
    }
    cout<<cost<<endl;
}