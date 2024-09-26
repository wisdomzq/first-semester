#include<iostream>
#include<stack>
using namespace std;
int n,m;
int a[1005];
int main()
{
    int ji=0;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            return 0;if(ji!=0)cout<<endl;
        ji++;
        
        while(m--)
        {
            for(int i=1;i<=n;i++) cin>>a[i];
            stack<int> s;
            int j=0,shu=1;
            while(j<n)
            {
                j++;
                s.push(j);
                while(!s.empty()&&s.top()==a[shu])
                {
                    s.pop(); 
                    shu++;
                  
                }
            }
            while(!s.empty()&&s.top()==a[shu])
            {
                s.pop();
                shu++;
            }
            if(shu==n+1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        
    }
   
}