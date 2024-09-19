#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned char sign[250010] = { 0 };//用于记录出现与否；
char a[21];
struct shu
{
   int num=0,ji=0;
}s[1510];
bool cmp(shu a,shu b)
{
    return a.num<b.num;
}
int cnt=0,temp; 
bool tote=true,totr=true;
int k,tmp,val;
bool re=true;
bool err=true;
int be=0;
int ju[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main()
{
   
       
   printf("Error:\n");
    tote=true,totr=true;
    
    while(scanf("%s", a) != EOF)
    {
         k=7,tmp=0;
         re=true;
         err=true;
         be=0;
        while(a[be]=='-') be++;
        if(a[be]!='3'&&a[be]!='6'&&ju[a[be]-'A']!=3&&ju[a[be]-'A']!=6)
        {
            printf("%s\n", a);
            err=false;
            tote=false;
        }
        for(int i=0;i<strlen(a);i++)
            {
                if(a[i]=='Q'||a[i]=='Z')
                {
                     printf("%s\n", a);
                    err=false;
                    tote=false;
                    break;
                }
                if(a[i]=='-') continue;  
                   if(a[i]>='A'&&a[i]<='Z')
                    {
                        a[i]=ju[a[i]-'A']+'0';
                    }
                    k--;
                    tmp+=pow(10,k)*(a[i]-'0');      
            }
            if(err)
            {
                val=tmp%1000000;
                if(tmp/1000000==6)
                    temp=val/8+125000;
                else
                    temp=val/8;
                if((sign[temp]&(1<<(val%8)))==0)
                sign[temp]|=(1<<(val%8));
                else
                {
                   totr=false;
                   if(tmp/1000000==3)
                   val+=3000000;
                   else
                     val+=6000000;
                     for(int i=1;i<=cnt;i++)
                  {
                    if(s[i].num==tmp)
                    {
                        s[i].ji++;
                        re=false;
                        break;
                    }
                  }
                
                if(re)
                {
                    ++cnt;
                    s[cnt].num=tmp;
                    s[cnt].ji=2;
                }
            }
    }
    memset(a, 0, sizeof(a));
    }
    sort(s+1,s+cnt+1,cmp);
    if(tote)printf("Not found.\n");
       printf("\n");
	printf("Duplication:\n");
    for(int i=1;i<=cnt;i++)
    {
        if(s[i].ji>1)
        {
           totr=false;
           printf("%d-%04d %d\n", s[i].num / 10000, s[i].num % 10000, s[i].ji);
            
        }
    }
    if(totr)printf("Not found.\n");
}


