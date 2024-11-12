#include<iostream>
#include<cmath>
using namespace std;
double a1,b,c,d;
bool flag=false;
double Sum(double a,double b,double k)
{
   if(k==0) return a+b;
   if(k==1) return a-b;
   if(k==2) return a*b;
   if(k==3)
   {
    if(fabs(b-0)>1e-6) return a/b; 
		else return -1000000;

   }
}
bool Calculate(double a,double b,double c,double d)
{
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
       for(int k=0;k<4;k++)
        {
            double s1=Sum(Sum(Sum(a,b,i),c,j),d,k);
            if(fabs(s1-24)<1e-6)
            return true;
            double s2=Sum(Sum(a,b,i),Sum(c,d,j),k);
            if(fabs(s2-24)<1e-6)
            return true;
            double s3=Sum(Sum(a,Sum(b,c,i),j),d,k);
            if(fabs(s3-24)<1e-6)
            return true;
            double s4=Sum(a,Sum(Sum(b,c,i),d,j),k);
            if(fabs(s4-24)<1e-6)
            return true;
            double s5=Sum(a,Sum(b,Sum(c,d,i),j),k);
            if(fabs(s5-24)<1e-6)
            return true;
        }
        return false;
}
void Swap(double &a,double &b)
{
    double temp;
    temp=a,a=b,b=temp;
}
void Perm(double p[],int l,int r)
{
    //遍历四个数的所有情况
    if(flag==true)return;
    if(l==r)
    {
        if(Calculate(p[0],p[1],p[2],p[3]))
        flag=true;
        return;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
           Swap(p[i],p[l]);
           Perm(p,l+1,r);
           Swap(p[i],p[l]);
        }
    }
}
int main()
{
    
    double a[5];
    while(cin>>a1>>b>>c>>d)
    {
       a[0]=a1,a[1]=b,a[2]=c,a[3]=d; 
       Perm(a,0,3);
       if(flag==true)cout<<"yes"<<endl;
         else cout<<"no"<<endl;
        flag=false;
    }
}