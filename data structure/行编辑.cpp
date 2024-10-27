#include<iostream>
#include<string>
using namespace std;
string in[1005];
void print(int num)
{
    for(int i=1;i<=num;i++)
    {
        cout<<in[i]<<endl;
    }
}
int main()
{
    string s;
    cin>>s;
    int num=0;
    while(s!="[/Text]")
    {
        getline(cin,s);
        in[++num]=s;
    }
    for(int i=1;i<=num-2;i++)
    in[i]=in[i+1];
    num-=2;
    while(getline(cin,s))
    {
       if(s[0]=='i')//插入新行
       {
            int n=2,p=0;
            while(s[n]>='0'&&s[n]<='9')//记录在第几行后加入
            {
                p=p*10+s[n]-'0';
                n++;
                
            }
            if(p>num) in[++num]=s.substr(n+1);
            else
            {
                for(int i=num;i>=p;i--)
                {
                    in[i+1]=in[i];
                }
                in[p]=s.substr(n+1);
                num++;
            }
            // print(num);
       }
       if(s[0]=='d')//删除行
       {
           int n=2,p=0;
           while(s[n]>='0'&&s[n]<='9')//记录删除第几行
           {
               p=p*10+s[n]-'0';
               n++;
           }
           if(p>num) continue;
           for(int i=p;i<=num;i++)
           {
               in[i]=in[i+1];
           }
           num--;
            //   print(num);
       }
       if(s[0]=='f')//插入行
       {
              int n=2,p=0;
              while(s[n]>='0'&&s[n]<='9')//记录在第几行后加入
              {
                p=p*10+s[n]-'0';
                n++;
              }
              int tem=0;
              int yidong[5],yd=0;
             for(int i=n+1;i<s.size();i++)
             {
                    if(s[i]>='0'&&s[i]<='9')
                    {
                        tem=tem*10+s[i]-'0';
                    }
                    if(s[i]=='/')
                    {
                      if(tem<=num)
                      {
                         yidong[++yd]=tem;
                      }
                       tem=0;
                       continue;
                    }
             }
             if(tem<=num)
             {
                 yidong[++yd]=tem;
             }
                for(int i=1;i<=yd;i++)
                {
                    in[p]+=in[yidong[i]];//插入行
                }
                for(int i=1;i<=yd;i++)
                {
                  in[yidong[i]]="";//删除行
                }
                string temp[1005];
                int t=0; 
                for(int i=1;i<=num;i++)
                {
                    if(in[i]!="")
                    {
                        temp[++t]=in[i];
                    }
                }
                for(int i=1;i<=t;i++)
                {
                    in[i]=temp[i];
                }
                num=t;
                // print(num);  
       }
       if(s[0]=='c')//字符串替换
       {
              int n=2;
              string s1,s2;
              while(s[n]!='/')
              {

                if(s[n]=='\\') 
                    s1+='/',n+=2;
                else s1+=s[n],n++;
              }
              n++;
              while(n<s.size())
              {
                if(s[n]=='\\') s2+='/',n+=2;
                else s2+=s[n],n++;
              }
                for(int i=1;i<=num;i++)
                {
                    int pos=0;
                    while((pos=in[i].find(s1,pos))!=-1)
                    {
                        in[i].replace(pos,s1.size(),s2);
                    }
                }
                
       }
    }
     print(num);
}