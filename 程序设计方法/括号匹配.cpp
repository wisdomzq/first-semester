#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
char a[100005];
bool ju[100005],use[100005];
int num[100005],r[100005],l[100005],pr[100005],pl[100005];
stack<char> s;
int n,ans=0,sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        int len=strlen(a),flag;
      while (!s.empty()) s.pop(); // 清空栈
        s.push(a[0]);
        for(int j=1;j<len;j++)
        {
            if(a[j]=='(')s.push(a[j]);
            if(a[j]==')')
            {
                if(!s.empty()&&s.top()=='(')s.pop();
                else s.push(a[j]);
            }
        }
        char p;
        if(!s.empty())
        {
            if(s.top()=='(') flag=1;
            if(s.top()==')') flag=-1;
            p=s.top();
            while(!s.empty())
        {
            if(!s.empty() && s.top()!=p)
            {
                ju[i]=1;
            }
           
            num[i]++;
            p=s.top();
            s.pop();
            
        }
        if(flag==1&&ju[i]==0)
        l[num[i]]++,pl[i]=num[i];
        
        if(flag==-1&&ju[i]==0)
        r[num[i]]++,pr[i]=num[i];
        }
        else flag=0,sum++,use[i]=1;
        
        

       
    }
    for(int i=1;i<=n;i++)
    {
      if(pr[i]!=0&&pl[i]==0&&use[i]==0)
      {
          if(l[pr[i]]>0)
          {
              ans++;
              l[pr[i]]--;
          }
      }
      else
        if(pr[i]==0&&pl[i]!=0&&use[i]==0)
        {
            if(r[pl[i]]>0)
            {
                ans++;
                r[pl[i]]--;
            }
        }
       
    }
    cout<<ans/2+sum/2<<endl;
}