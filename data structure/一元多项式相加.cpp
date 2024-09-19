#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,T;
struct item
{
    int x;
    int z;
}x1[10005],x2[10005],x3[10005],j1[10005],j2[10005];
bool cmp(item a,item b)
{
    return a.z<b.z;
}
int main()
{
    
    while(cin>>T)
    {
       if(T==0) return 0;
       else
       {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x1[i].x>>x1[i].z; 
        }

        sort(x1+1,x1+n+1,cmp);
        for(int i=1;i<n;i++)
        {
            cout<<"<"<<x1[i].x<<","<<x1[i].z<<">"<<","; 
        }
         cout<<"<"<<x1[n].x<<","<<x1[n].z<<">"<<endl;
         cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>x2[i].x>>x2[i].z; 
        }
        sort(x2+1,x2+m+1,cmp);
        for(int i=1;i<m;i++)
        {
            cout<<"<"<<x2[i].x<<","<<x2[i].z<<">"<<","; 
        }
         cout<<"<"<<x2[m].x<<","<<x2[m].z<<">"<<endl;
         cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>x3[i].x>>x3[i].z; 
        }
        sort(x3+1,x3+k+1,cmp);
        for(int i=1;i<k;i++)
        {
            cout<<"<"<<x3[i].x<<","<<x3[i].z<<">"<<","; 
        }
         cout<<"<"<<x3[k].x<<","<<x3[k].z<<">"<<endl;
         int ji=0;
         int j=1,i=1;
         while(i<=n&&j<=m)
            {
                if(x1[i].z==x2[j].z)
                {
                   j1[++ji].x=x1[i].x+x2[j].x;
                   j1[ji].z=x1[i].z;
                   ++i,++j;
                   if(i>n)
                   {
                    for(;j<=m;j++)
                    {
                        j1[++ji].x=x2[j].x;
                        j1[ji].z=x2[j].z;
                    }
                   }
                   else
                   if(j>m)
                   {
                    for(;i<=n;i++)
                    {
                        j1[++ji].x=x1[i].x;
                        j1[ji].z=x1[i].z;
                    }
                   }
                }
                else{
                     if(x1[i].z<x2[j].z)
                {
                    j1[++ji].x=x1[i].x;
                    j1[ji].z=x1[i].z;
                    ++i;
                    if(i>n)
                    {
                        for(;j<=m;j++)
                        {
                            j1[++ji].x=x2[j].x;
                            j1[ji].z=x2[j].z;
                        }
                    }
                }
                else
                if(x1[i].z>x2[j].z)
                {
                    j1[++ji].x=x2[j].x;
                    j1[ji].z=x2[j].z;
                    ++j;
                    if(j>m)
                    {
                        for(;i<=n;i++)
                        {
                            j1[++ji].x=x1[i].x;
                            j1[ji].z=x1[i].z;
                        }
                    }
                }
                }
               
            }
        bool flag=false;
            for(i=1;i<ji;i++)
            {
                if(j1[i].x!=0)
                flag=true,cout<<"<"<<j1[i].x<<","<<j1[i].z<<">"<<",";
                else
                continue;
            }
            if(j1[ji].x!=0)
            flag=true,cout<<"<"<<j1[ji].x<<","<<j1[ji].z<<">"<<endl;
            else{
                if(flag)
                cout<<endl;
                if(!flag)
                cout<<"<0,0>"<<endl;
            }
      
        j=1,i=1;
        int ji1=0;
         while(i<=ji&&j<=k)
            {
                if(j1[i].z==x3[j].z)
                {
                   j2[++ji1].x=j1[i].x+x3[j].x;
                   j2[ji1].z=j1[i].z;
                   ++i,++j;
                   if(i>ji)
                   {
                    for(;j<=k;j++)
                    {
                        j2[++ji1].x=x3[j].x;
                        j2[ji1].z=x3[j].z;
                    }
                   }
                   else
                   if(j>k)
                   {
                    for(;i<=ji;i++)
                    {
                        j2[++ji1].x=j1[i].x;
                        j2[ji1].z=j1[i].z;
                    }
                   }
                }
                else{
                    if(j1[i].z<x3[j].z)
                    {
                        j2[++ji1].x=j1[i].x;
                        j2[ji1].z=j1[i].z;
                        ++i;
                        if(i>ji)
                        {
                            for(;j<=k;j++)
                            {
                                j2[++ji1].x=x3[j].x;
                                j2[ji1].z=x3[j].z;
                            }
                        }
                    }
                    else
                    if(j1[i].z>x3[j].z)
                    {
                        j2[++ji1].x=x3[j].x;
                        j2[ji1].z=x3[j].z;
                        ++j;
                        if(j>k)
                        {
                            for(;i<=ji;i++)
                            {
                                j2[++ji1].x=j1[i].x;
                                j2[ji1].z=j1[i].z;
                            }
                    }
                }
                  
                }
               
            }
            flag=false;
            for(i=1;i<ji1;i++)
            {
                if(j2[i].x!=0)
                flag=true,cout<<"<"<<j2[i].x<<","<<j2[i].z<<">"<<",";
                else
                continue;
            }
            if(j2[ji1].x!=0)
            flag=true,cout<<"<"<<j2[ji1].x<<","<<j2[ji1].z<<">"<<endl;
            else{
                if(flag)
                cout<<endl;
                if(!flag)
                cout<<"<0,0>"<<endl;
            }
       }

    }
   
}