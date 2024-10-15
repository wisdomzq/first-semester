#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct point{
    double x,y;
    int index;
}Point;
Point px[100005],py[100005],temp[100005];
int n;
bool cmp_x(Point a,Point b)
{
    return a.x<b.x;
}
bool cmp_y(Point a,Point b)
{
    return a.y<b.y;
}
double dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


/* 计算点集X在[l,r]区间内的两点最近距离
 * 点集Y的元素与X内相同
 * 点集temp待用
 * 注：X在[l,r]区间已经按照x坐标排序，Y在[l,r]区间已经按照y坐标排序 */
double mindistance(int l,int r)
{
    double d=10000000;
    if(l+1==r)
    {
        return dis(px[l],px[r]);
    }
    if(l+2==r)
    {
        return min(dis(px[l],px[l+1]),min(dis(px[l],px[r]),dis(px[l+1],px[r])));
    }
    int mid=(l+r)/2;//“分”，中位数下标

    double d1=mindistance(l,mid);//“分”，左半部分最近距离
    double d2=mindistance(mid+1,r);//“分”，右半部分最近距离
    d=min(d1,d2);
    int cnt=0;//“治”，记录Temp点的个数
    for(int i=l;i<=r;i++)
    {
        if(fabs(px[mid].x-px[i].x)<=d)
        {
            temp[++cnt]=px[i];
        }
    }
    sort(temp+1,temp+cnt+1,cmp_y);//对Temp点按照y坐标排序
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i+1;j<=cnt;j++)
        {
            if(temp[j].y-temp[i].y>=d)
            {
                break;
            }
            d=min(d,dis(temp[i],temp[j]));
        }
    }
    return d;

}
int main()
{
    while(cin>>n)
    {
    if(n==0)break;
    for(int i=1;i<=n;i++)cin>>px[i].x>>px[i].y;
    sort(px+1,px+n+1,cmp_x);
    printf("%.2lf\n",mindistance(1,n)/2);
    }
}

// #include <iostream>  
// #include <cstdio>  
// #include <cstring>  
// #include <cmath>  
// #include <algorithm>  
// using namespace std;  
// const double INF = 1e20;  
// const int N = 100005;  
  
// struct Point  
// {  
//     double x;  
//     double y;  
// }point[N];  
// int n;  
// int tmpt[N];  
   
// bool cmpxy(const Point& a, const Point& b)  
// {  
//     if(a.x != b.x)  
//        return a.x < b.x;  
//     return a.y < b.y;  
// }  
   
// bool cmpy(const int& a, const int& b)  
// {  
//     return point[a].y < point[b].y;  
// }  
 
// double min(double a, double b)  
// {  
//     return a < b ? a : b;  
// }  
   
// double dis(int i, int j)  
// {  
//     return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)  
//                 + (point[i].y-point[j].y)*(point[i].y-point[j].y));  
// }  
   
// double Closest_Pair(int left, int right)  
// {  
//     double d = INF;  
//     if(left==right)  
//         return d;  
//     if(left + 1 == right)  
//         return dis(left, right);  
//     int mid = (left+right)>>1;  
//     double d1 = Closest_Pair(left,mid);  
//     double d2 = Closest_Pair(mid+1,right);  
//     d = min(d1,d2);  
//     int i,j,k=0;  
//     //分离出宽度为d的区间  
//     for(i = left; i <= right; i++)  
//     {  
//         if(fabs(point[mid].x-point[i].x) <= d)  
//             tmpt[k++] = i;  
//     }  
//     sort(tmpt,tmpt+k,cmpy);  
//     //线性扫描  
//     for(i = 0; i < k; i++)  
//     {  
//         for(j = i+1; j < k && point[tmpt[j]].y-point[tmpt[i]].y<d; j++)  
//         {  
//             double d3 = dis(tmpt[i],tmpt[j]);  
//             if(d > d3)  
//                 d = d3;  
//         }  
//     }  
//     return d;  
// }  
   
   
// int main()  
// {  
    
//         scanf("%d",&n);  
       
//         for(int i = 0; i < n; i++)  
//             scanf("%lf %lf",&point[i].x,&point[i].y);  
//         sort(point,point+n,cmpxy);  
//         printf("%.2lf\n",Closest_Pair(0,n-1)/2);  
      
   
// } 