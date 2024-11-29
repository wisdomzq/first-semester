#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
bool bmp(char a,char b)
{
    return a>b;
}
bool Divide_5(string &s)
{
     if(s[s.size()-1]=='0'||s[s.size()-1]=='5')
     {
         return true;
     }
     for(int i=s.size()-1;i>=0;i--)
     {
         if(s[i]=='5') 
         {
            for(int j=i;j<s.size();j++)
            {
                s[j]=s[j+1];
            }
            s[s.size()-1]='5';
            return true;
         }
     }
        return false;
}
bool Divide_3(string &s)
{
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        sum+=s[i]-'0';
    }
    if(sum%3==0) return true;
    int tag=sum%3;
    for(int i=s.size()-2;i>=0;i--)
    {
        if((s[i]-'0')%3==tag)
        {
        s.erase(s.begin()+i);
        return true;
        }
    }
    tag=3-tag;
    for(int i=s.size()-2;i>=0;i--)
    {
        if((s[i]-'0')%3==tag)
        {
            s.erase(s.begin()+i);
            for(int j=i-1;j>=0;j++)
            {
               if((s[j]-'0')%3==tag)
               {
                  s.erase(s.begin()+j);
                  return true;
               }
            }
        }
    }
    return false;
}
int main()
{
    
    while(cin>>s)
    {
        
        sort(s.begin(),s.end(),bmp);    
        if(Divide_5(s)&&Divide_3(s))
        {
            if(s.front()=='0')
            {
                cout<<0<<endl;
            }
            else
            cout<<s<<endl;
        }
        else
        {
            cout<<"impossible"<<endl;
        }
    }
}