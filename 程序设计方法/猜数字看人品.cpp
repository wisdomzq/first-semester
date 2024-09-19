#include<iostream>
#include<cstring>
using namespace std;
bool check;
int main()
{
    int n,high=11,low=0;
    char a[12],b[12],x[12]="low",y[12]="high",z[12]="too";
    cin>>n;
    check=true;
    while(n!=0)
    {
      cin>>a>>b;
       if(!strcmp(a,z))
       {
        if(!strcmp(b,x))
        {
         if(n>=high)check=false;
          low=max(low,n);
        }
        if(!strcmp(b,y))
       {
        if(n<=low)check=false;
          high=min(high,n);
       }
       if(high<low)check=false;
       }
       else
       {
        if(n<high&&n>low&&check) cout<<"Tom may be honest"<<endl;
        else cout<<"Tom is dishonest"<<endl;
        high=11,low=0;
        check=true;
       }
       cin>>n;
      
    }
}