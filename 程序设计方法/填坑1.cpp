#include<iostream>
#include<stack>
using namespace std;
#define ll long long
ll n;
int a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin>>n)
    {
       ll maxx=0;
       stack<int> s;
        for(int i=1;i<=n;i++)
            cin>>a[i],maxx=max(maxx,(ll)a[i]);
        for(int i=1;i<=n;i++)
        {
            a[i]=(maxx-a[i])%2;
            if(!s.empty()&&s.top()==a[i])
                s.pop();
            else
                s.push(a[i]);
        }
        
        if(s.size()<2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
         
    }
  
}