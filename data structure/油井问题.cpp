#include<iostream>
#include<algorithm>
using namespace std;
int dis[2000005];
//将p到r的数据排序,作为分割后的数组排序
void selectsort(int p[],int l,int r)
{
  for(int i=l;i<r;i++)
  {
    for(int j=i+1;j<=r;j++)
    {
        if(p[i]>p[j])
        swap(p[i],p[j]);
    }
  }
}
//在l和r之间寻找中位数的索引
int searchmid(int p[],int l,int r)
{
    selectsort(p,l,r);
    return (l+r)/2;
}
//对p和r之间的数以x为基准进行划分,返回基准的索引
int partition(int p[],int l,int r,int x)
{
    int i=l,j=r;
    while(1)
    {
        while(p[i]<x&&i<r)i++;
        while(p[j]>x&&j>l)j--;
        if(i>=j) break;
        swap(p[i],p[j]);
        i++,j--;
    }
    return j;
}
//在p数组的l和r之间寻找第k小的元素
int select(int p[],int l,int r,int k)
{
   if(r-l<5)
   {
    selectsort(p,l,r);
    return p[l+k-1];
   }
   //否则，分成n/5组，将每一组的中位数移到最前面
   for(int i=0;i<=(r-l-4)/5;i++)
   {
       int index=searchmid(p,l+i*5,l+i*5+4);
       swap(p[index],p[i+l]);
   }
   //以各组数中位数的中位数作为基准
    int x = select(p, l, l + (r-l-4)/5, (r-l-4)/10+1);
   int i=partition(p,l,r,x);
   int len=i-l+1;
   if(len>=k)
   {
    return select(p, l, i, k);
   }
   else return select(p,i+1,r,k-len);
}
int main()
{
    int x,y;
    int n=0;
   while(scanf("%d,%d",&x,&y) != EOF)
    {
        dis[++n]=y;
    }
    cout<<select(dis,1,n,(1+n)/2)<<endl;
}
// #include<iostream>
// #include<cstdio>
// #include<random>

// using namespace std;

// int n, k, len;

// //选择排序
// void SelectSort(int a[], int p, int r);
// //将x作为基准数将数组分割，返回x的位置
// int Partition(int a[], int p, int r, int x);
// //交换两个元素
// void Swap(int &a, int &b);
// //找每组的中位数,返回中位数的位置i
// int SearchMid(int a[], int p, int r);
// //线性划分
// int Select(int a[], int p, int r, int k);
// int dis[2000005];
// int main()
// {
//     //输入数组长度n
    
//     //输入数组
    
//     int x,y;
//     int n=0;
//     while(scanf("%d,%d",&x,&y) != EOF)
//     {
//         dis[++n]=y;
//     }
   
//     int res = Select(dis, 1, n , (n+1)/2);
//     cout<<res<<endl;
 
//     return 0;
// }

// void SelectSort(int a[], int p, int r)
// {
//     for (int i = p; i < r; ++i)
//     {
//         int index = i;
//         for (int j = i + 1; j <= r; ++j)
//         {
//             if (a[j] < a[index])
//             {
//                 index = j;
//             }
//         }
//         Swap(a[i], a[index]);
//     }
// }

// int Partition(int a[], int p, int r, int x)
// {
//     //i指向首元素的前一个位置，j指向尾元素的后一个位置
//     int i = p - 1, j = r + 1;
//     while (1)
//     {
//         //i从基准数右边的元素开始找，直到找到第一个大于等于基准数的元素
//         while (a[++i] < x && i < r);
//         //j从尾元素开始找，直到找到第一个小于等于基准数的元素
//         while (a[--j] > x && j > p);
//         //若i>=j，说明基准数的位置已找到，为j
//         if (i >= j)
//         {
//             break;
//         }
//         //交换两个元素，使得基准数左边的数均不大于它，右边的数均不小于它
//         Swap(a[i], a[j]);
//     }
//     //返回基准数的位置
//     return j;
// }

// void Swap(int &a, int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

// int SearchMid(int a[], int p, int r)
// {
//     //建立与数组a同等大小的数组b
//     int *b = new int[r - p + 1];
//     //用数组b存放数组a（注意此时b的首地址为0，而a的首地址为p）
//     for (int i = p; i <= r; ++i)
//     {
//         b[i - p] = a[i];
//     }
//     //将数组b排序，b[(r-p+1)/2]为中位数
//     SelectSort(b, 0, r - p);
//     for (int i = p; i <= r; ++i)
//     {
//         if (a[i] == b[(r - p + 1) / 2])
//         {
//             return i;
//         }
//     }
//     delete []b;
//     return 0;
// }

// int Select(int a[], int p, int r, int k)
// {
//     if (r - p < 5)
//     {
//         SelectSort(a, p, r);
//         return a[p + k - 1];
//     }
//     //分成n/5组，每组5个，找到每组的中位数并将它放到数组首元素的位置
//     for (int i = 0; i <= (r - p - 4) / 5; ++i)
//     {
//         int mid = SearchMid(a, p + 5 * i, p + 5 * i + 4);
//         Swap(a[mid], a[p + i]);
//     }
//     //找到各组中位数的中位数
//     int x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10 + 1);
//     //按照中位数划分
//     int i = Partition(a, p, r, x);
//     //求较小数数组的长度
//     len = i - p + 1;
//     //若较小数数组的长度小于等于k，说明第k小的元素在这个数组内，将其递归
//     if (k <= len)
//     {
//         return Select(a, p, i, k);
//     }
//     //否则，说明第k小的元素在较大数数组，将其递归
//     else
//     {
//         return Select(a, i + 1, r, k - len);
//     }
// }
