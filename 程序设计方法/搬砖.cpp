#include<iostream>
using namespace std;
unsigned long long ans=0;
int a[500005],b[500005];
void Merge(int ori[],int tmp[],int start,int mid,int end)
{
    int i=start,j=mid+1,k=start;
    while(i!=mid+1&&j!=end+1)
    {
        if(ori[i]>ori[j])
        tmp[k++]=ori[j++],ans+=mid-i+1;
        else tmp[k++]=ori[i++];
    }
    while(i!=mid+1)tmp[k++]=ori[i++];
    while(j!=end+1)tmp[k++]=ori[j++];
    for(i=start;i<=end;i++)ori[i]=tmp[i];
}
void Mergesort(int ori[],int tmp[],int start,int end)
{
    int mid;
    if(start<end)
    {
        mid=start+(end-start)/2;
        Mergesort(ori,tmp,start,mid);
        Mergesort(ori,tmp,mid+1,end);
        Merge(ori,tmp,start,mid,end);
    }
    return ;
}
int main()
{
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    Mergesort(a,b,0,n-1);
    cout<<ans<<endl;
}
