#include<iostream>
#include<cstring>
using namespace std;
char standard[11]="fattyhappy";
int main()
{
   int T;
   cin>>T;
   while(T--)
   {
         char a[1005];
         cin>>a;
         int len=strlen(a);
         bool tot=true;
        for(int i=0;i<=len-10;i++)
        {
           int num=0,error[11];
           bool ju=true;
           for(int j=i;j<i+10;j++)
           {
               if(a[j]!=standard[j-i])  error[++num]=j;
               if(num>=3) 
               {
                ju=false;
                break;
               }
           }
           if(!ju) continue;
           if(num==0)
           {
            cout<<i+3<<" "<<i+4<<endl;
            tot=false;
           }
           if(num==1)
           {
             for(int k=0;k<i;k++)
                if(a[k]==standard[error[1]-i]) {
                  cout<<error[1]+1<<" ";  tot=false; cout<<k+1<<endl;break;
                }
                if(tot)
                 for(int k=i+10;k<len;k++)
                if(a[k]==standard[error[1]-i]) {
                   cout<<error[1]+1<<" ";  tot=false; cout<<k+1<<endl;break;
                }
            if(tot) continue;
           }
           if(num==2)
           {
             if(a[error[1]]==standard[error[2]-i]&&a[error[2]]==standard[error[1]-i])
             {
                 cout<<error[1]+1<<" "<<error[2]+1<<endl;
                 tot=false;
             }
             else continue;
           }
           if(!tot) break;
        }
        if(tot)cout<<"-1"<<endl;
    }   
}
