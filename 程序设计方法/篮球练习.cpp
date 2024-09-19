#include<iostream>
using namespace std;
long long a[25][25];
bool b[25][25];
int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1+=2;y1+=2;x2+=2;y2+=2;
    b[x2][y2]=b[x2-1][y2-2]=b[x2-1][y2+2]=b[x2-2][y2-1]=b[x2-2][y2+1]=b[x2+1][y2-2]=b[x2+1][y2+2]=b[x2+2][y2-1]=b[x2+2][y2+1]=1;
    for(int i=2;i<=x1;i++)if(!b[i][2])a[i][2]=1;
    else break;
    for(int i=2;i<=y1;i++)if(!b[2][i])a[2][i]=1;
    else break;
    for(int i=3;i<=x1;i++)
    {
        for(int j=3;j<=y1;j++)
        {
            if(!b[i][j])a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
 
    if(b[2][2]==1)cout<<0<<endl;
    else
    cout<<a[x1][y1]<<endl;
}