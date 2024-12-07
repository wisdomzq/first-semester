#include<iostream>
using namespace std;
int n;
int a[100005];
void HeapSort(int l,int r)
{
    int mid=(l+r)/2;
    for(int i=mid;i>=l;i--)
    {
        int k=i;
        while(k*2<=r)
        {
            int j=k*2;
            if(j+1<=r&&a[j+1]>a[j]) j++;
            if(a[j]>a[k])
            {
                swap(a[j],a[k]);
                k=j;
            }
            else break;
        }
    }


}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int k=0;k<3;k++)
    {
        HeapSort(1,n);
        for(int j=1;j<=n;j++) cout<<a[j]<<" ";
        cout<<endl;
        swap(a[1],a[n]);
        n--;
    }
    
}