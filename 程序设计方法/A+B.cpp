#include<iostream>
#include<cstring>
using namespace std;
char a[100005],b[100005],c[100005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       cin>>a>>b;
       int tmp=0;
       bool check=false;
       int lena=strlen(a),lenb=strlen(b),len;
       if(lena>=lenb)
       {
        for(int i=lenb-1;i>=0;i--)
        {
          
            if(b[i]=='1'&&a[lena-lenb+i]=='1')
            {
                if(tmp==0) c[lena-lenb+i]='0',tmp=1;
               else  c[lena-lenb+i]='1',tmp=1;               
            }
            if(((b[i]=='1')&&(a[lena-lenb+i]=='0'))||((b[i]=='0')&&(a[lena-lenb+i]=='1')))
            {
                if(tmp==0) c[lena-lenb+i]='1';
                else c[lena-lenb+i]='0',tmp=1;
            }
             if(b[i]=='0'&&a[lena-lenb+i]=='0')
             {
                if(tmp==0) c[lena-lenb+i]='0';
                else c[lena-lenb+i]='1',tmp=0;
             }
       }
       for(int i=lena-lenb-1;i>=0;i--)
       {
        if(a[i]=='1')
        {
            if(tmp==0)c[i]='1';
            else c[i]='0';
        }
        else
        {
            if(tmp==0)c[i]='0';
            else c[i]='1',tmp=0;
        }
       }
       if(tmp==1) check=true,len=lena+3;
       else len=lena+2;
       for(int i=1;i<=len-lena;i++)cout<<" ";
       cout<<a<<endl;
       cout<<'+';
       for(int i=1;i<=len-lenb-1;i++)cout<<' ';
       cout<<b<<endl;
       for(int i=1;i<=len;i++)cout<<'-';
       cout<<endl;
       cout<<"  ";
       if(check)cout<<1;
       for(int i=0;i<lena;i++)cout<<c[i];
       cout<<endl;
    }
    if(lena<lenb)
       {
        for(int i=lena-1;i>=0;i--)
        {
          
            if(a[i]=='1'&&b[lenb-lena+i]=='1')
            {
                if(tmp==0) c[lenb-lena+i]='0',tmp=1;
               else  c[lenb-lena+i]='1',tmp=1;               
            }
            if(((a[i]=='1')&&(b[lenb-lena+i]=='0'))||((a[i]=='0')&&(b[lenb-lena+i]=='1')))
            {
                if(tmp==0) c[lenb-lena+i]='1';
                else c[lenb-lena+i]='0',tmp=1;
            }
             if(a[i]=='0'&&b[lenb-lena+i]=='0')
             {
                if(tmp==0) c[lenb-lena+i]='0';
                else c[lenb-lena+i]='1',tmp=0;
             }
       }
       for(int i=lenb-lena-1;i>=0;i--)
       {
        if(b[i]=='1')
        {
            if(tmp==0)c[i]='1';
            else c[i]='0';
        }
        else
        {
            if(tmp==0)c[i]='0';
            else c[i]='1',tmp=0;
        }
       }
       if(tmp==1) check=true,len=lenb+3;
       else len=lenb+2;
       for(int i=1;i<=len-lena;i++)cout<<" ";
       cout<<a<<endl;
       cout<<'+';
       for(int i=1;i<=len-lenb-1;i++)cout<<' ';
       cout<<b<<endl;
       for(int i=1;i<=len;i++)cout<<'-';
       cout<<endl;
       cout<<"  ";
       if(check)cout<<1;
       for(int i=0;i<lenb;i++)cout<<c[i];
       cout<<endl;
    }
 }
}