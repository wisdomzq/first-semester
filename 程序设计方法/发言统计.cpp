#include<iostream>
#include<cstring>
using namespace std;
char mapp[1005][25];
char a[25];
int main()
{
    int n,cnt=0;
    bool ju=true;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        int len=strlen(a);
        if(len>10)
        {
            ju=true;
            if(cnt>0)
            for(int j=1;j<=cnt;j++)
            {
                if(!strcmp(a,mapp[j]))
                {
                    ju=false;
                    break;
                }
            }
           if(ju)
           {
            ++cnt;
            for(int j=0;j<len;j++)
                mapp[cnt][j]=a[j];
           } 
        }
        memset(a,0,sizeof(a));
    }
    cout<<cnt<<endl;

}
