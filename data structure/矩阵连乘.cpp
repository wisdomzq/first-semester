#include<iostream>
using namespace std;
#define ll long long
ll a[1005],n;
ll m[1005][1005],s[1005][1005];
void chain()//构造乘法表
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=1;r<n;r++)
    {
        for(int i=1;i<=n-r;i++)
        {
            int j=i+r;
            m[i][j]=m[i][i]+m[i+1][j]+a[i-1]*a[i]*a[j];
            //设P最后乘法在Ak后断开, 即 A[1:k]*A[k+1:n]
            //那么P的计算量为 T[1,k] + T[k+1,n] + q0*qk*qn. 
            //若P最优,则P在A[1:k]和A[k+1:n]上也最优 
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                ll t=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;//记录最小成本的切割点
                }
            }
        }
    }
}
void traceback(ll i,ll j)//输出最优解
{
    if(i==j)
    {
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    traceback(i,s[i][j]);
    
    traceback(s[i][j]+1,j);
    cout<<")";
}
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    chain();
    cout<<m[1][n]<<endl;
    traceback(1,n);
    cout<<endl;
}