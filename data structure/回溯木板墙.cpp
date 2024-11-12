#include<iostream>
#include<stack>
using namespace std;
long long s[100005];
int T,n;
long long MaxHeight(long long p[])
{
     int i=0;
     stack<int> h;
     long long ans=0;
     while(i<n)
     {
        if(h.empty()||p[i]>=p[h.top()])
        {
            h.push(i);
            i++;
        }//构造单调递增栈
        else
        {
            int tmp=h.top();
            h.pop();
            long long area=p[tmp]*(h.empty()?i:i-h.top()-1); //当前木板形成的最大面积，即木板高度乘以木板宽度
            //木板宽度即为当前木板的下标减去栈顶元素的下标(即第一个小于它高度的木板)减一
            ans=max(ans,area);
        }
     } 
     while(!h.empty())
        {
            int tmp=h.top();
            h.pop();
            long long area=p[tmp]*(h.empty()?i:i-h.top()-1);
            ans=max(ans,area);
        }
     return ans;
}
int main()
{
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)  cin>>s[i];
        cout<<MaxHeight(s)<<endl;
    }
}