#include<iostream>
using namespace std;
int a[105][105],hm[105],lm[105];
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j],hm[i]=max(hm[i],a[i][j]);
   for(int j=1;j<=n;j++)
     for(int i=1;i<=m;i++)
      lm[j]=max(lm[j],a[i][j]);
      for(int i=1;i<=m;i++)
      {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]<hm[i]&&a[i][j]<lm[j])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
      }
       cout<<"YES"<<endl;
}