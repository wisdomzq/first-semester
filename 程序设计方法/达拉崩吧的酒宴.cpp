#include<iostream>
#include<cmath>
using namespace std;
#define ull unsigned long long
int main()
{
  ull n,m;
  cin>>n;
  while(n--)
  {
    cin>>m;
    if(m==1)cout<<0<<endl;
    else
    {
    ull num=0,p=1;
    
    while(p<m)
    {
       p*=2;
       num++;
    }
   
    cout<<num<<endl;
    }
   
  }
}