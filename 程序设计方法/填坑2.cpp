#include<iostream>
#include<stack>
#include<cstring>
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
       bool flag=true;
       stack<int> s;
       for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,(ll)a[i]);
       s.push(a[1]);
        for(int i=2;i<=n;i++)
        {
           
            
            if(s.empty())s.push(a[i]);
            else
            {
                if(!s.empty()&&s.top()<a[i])
                   {
                    flag=false;
                    break;
                   }
                   if(s.top()==a[i])
                   {
                       s.pop();
                   }
                   else
                   {
                       s.push(a[i]);
                   }
            }
        }
        if(!flag)
        {
            cout<<"NO"<<endl;
            
        }
        else
        {
              if(!s.empty()&&flag)
        {
            if(s.size()>1)cout<<"NO"<<endl;
            else
            {
                if(s.top()==maxx)
                cout<<"YES"<<endl;
                else
                cout<<"NO"<<endl;
            }    
        }
        else
          if(flag&&s.empty())cout<<"YES"<<endl;  
       
         
    }
        }
}