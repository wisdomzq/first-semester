#include<iostream>
#include<string>
using namespace std;
int a[100005];
int n,mn;
int cutoff=5;
int midnum[100005];
void convert(string s)
{
    int len=s.size(),num=0;
    int flag=1,begin=0;
    if(s[0]=='-')
    {
        flag=-1;
        begin++;
    }
    for(int i=begin;i<len;i++)
    {
        num=num*10+(s[i]-'0');
    }
    a[++n]=num*flag;
}
void InsertSort(int p[],int l,int r)
{
    for(int i=l+1;i<=r;i++)
    {
        int tmp=p[i],j;
        for(j=i;j>l&&p[j-1]>tmp;j--)
        {
            p[j]=p[j-1];
        }
        p[j]=tmp;
    }
}
int Median3(int p[],int l,int r)
{
    int mid=(l+r)/2;
    if(p[l]>p[mid]) swap(p[l],p[mid]);
    if(p[l]>p[r]) swap(p[l],p[r]);
    if(p[mid]>p[r]) swap(p[mid],p[r]);
    int tmp=p[mid];
    swap(p[mid],p[r-1]);
    return tmp;
}
void Qsort(int p[],int l,int r)
{
    if(r-l<cutoff)
    {
        InsertSort(p,l,r);
        return;
    }
    midnum[++mn]=Median3(p,l,r);
    int i=l,j=r-1;
    int pivot=p[r-1];
    while(1)
    {
        while(p[++i]<pivot&&i<j);
        while(p[--j]>pivot&&i<j) ;
        if(i<j) swap(p[i],p[j]);
        else break;
    }
    swap(p[i],p[r-1]);
    Qsort(p,l,i-1);
    Qsort(p,i+1,r);
}
int main()
{
    string s;
    while(cin>>s)
    {
       if(s=="#") break;
       convert(s);
    }
    Qsort(a,1,n);
    cout<<"After Sorting:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Median3 Value:"<<endl;
    if(mn==0) 
    {
        cout<<"none"<<endl;
        return 0;
    }
    else
    for(int i=1;i<=mn;i++)
    {
        cout<<midnum[i]<<" ";
    }
    cout<<endl;
}