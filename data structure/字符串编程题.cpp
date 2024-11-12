#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007
int n;
char s[1000005];
int ne[1000005],ans[1000005];//ne是next数组,ans是公共前缀的个数
//ne[i]表示长度为i的字符串的最长前缀后缀的长度
//ans[i]表示长度为i的字符串的公共前缀的个数, ans[i]=ans[ne[i]]+1,
//ans[ne[i]]为长度为ne[i]的字符串的公共前缀的个数，加1是因为整个长度为ne[i]的字符串也算一个前缀
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int len=strlen(s);
        int l=0;
        ans[1]=1;
        for(int j=1;j<len;j++)//j是后缀的末尾,l是前缀的末尾
        {
            while(l>0&&s[j]!=s[l])//不匹配
                l=ne[l];
            if(s[j]==s[l])//匹配
                l++;
            ne[j+1]=l;
            ans[j+1]=ans[l]+1; //ans[j+1]表示长度为j+1的字符串的公共前缀的个数, 迭代一次
        }
        l=0;
        long long cnt=1;
        for(int j=0;j<len;j++)
        {
            while(l>0&&s[j]!=s[l])
                l=ne[l];
            if(s[j]==s[l]) l++;
            while(l*2>j+1) l=ne[l];//重复一遍，保证前后缀没有重叠
            cnt=(cnt*(ans[l]+1))%mod;
        }
        
        cout<<cnt<<endl;
    }
}