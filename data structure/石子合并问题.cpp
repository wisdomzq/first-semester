#include<iostream>
using namespace std;
int a[205],n;
int f[205][205],s[205],f1[205][205];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],f[i][i]=f[i+n][i+n]=0,f1[i][i]=f1[i+n][i+n]=0,s[i]=s[i-1]+a[i],a[i+n]=a[i];
    for(int i=n+1;i<=2*n;i++)s[i]=s[i-1]+a[i];
     for(int r=1;r<n;r++)
    {
        for(int i=1;i<=2*n-r;i++)
        {
            int j=i+r;
            f[i][j]=f[i][i]+f[i+1][j]+s[j]-s[i-1];
            f1[i][j]=f1[i][i]+f1[i+1][j]+s[j]-s[i-1];
            for(int k=i+1;k<=j;k++)
            {
                f[i][j]=max(f[i][j],f[i][k-1]+f[k][j]+s[j]-s[i-1]);
                f1[i][j]=min(f1[i][j],f1[i][k-1]+f1[k][j]+s[j]-s[i-1]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    f1[1][n]=min(f1[1][n],f1[i][i+n-1]),f[1][n]=max(f[1][n],f[i][i+n-1]);
    cout<<f1[1][n]<<endl;
    cout<<f[1][n]<<endl;
    
}
// #include <iostream> 
// #include <cstring> 
// using namespace std;
// const int N = 310; 
// int n; 
// int a[N], s[N]; // s数组用于前缀和优化
// int f[N][N]; // f[i][j]表示合并第i~j堆石子的最小代价
 
// int main() { 
// 	cin >> n; 
// 	for (int i = 1; i <= n; i ++ ) 
// 		cin >> a[i];
 
// 	// 前缀和优化
// 	for (int i = 1; i <= n; i ++ ) 
// 		s[i] = s[i - 1] + a[i];
	
// 	memset(f, 0x3f, sizeof f); // 初值无穷大
// 	for (int i = 1; i <= n; i ++ ) 
// 		f[i][i] = 0; // 一堆石子不需要合并
	
// 	// 枚举区间长度
// 	for (int len = 2; len <= n; len ++ )
// 	{
// 	    // 枚举区间起点
// 	    for (int i = 1; i + len - 1 <= n; i ++ )
// 	    {
// 	        int j = i + len - 1; // 区间终点
	
// 	        // 枚举划分位置
// 	        for (int k = i; k < j; k ++ )
// 	        {
// 	            f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
// 	        }
// 	    }
// 	}
	
// 	cout << f[1][n] << endl;	
// 	return 0;
// }


// #include <iostream>
// #include <string.h>
// #include <stdio.h>
 
// using namespace std;
// const int INF = 1 << 30;
// const int N = 205;
 
// int mins[N][N];
// int maxs[N][N];
// int sum[N],a[N];
// int minval,maxval;
// int n;
 
// int getsum(int i,int j)
// {
//     if(i+j >= n) return getsum(i,n-i-1) + getsum(0,(i+j)%n);
//     else return sum[i+j] - (i>0 ? sum[i-1]:0);
// }
 
// void Work(int a[],int n)
// {
//     for(int i=0;i<n;i++)
//         mins[i][0] = maxs[i][0] = 0;
//     for(int j=1;j<n;j++)
//     {
//         for(int i=0;i<n;i++)
//         {
//             mins[i][j] = INF;
//             maxs[i][j] = 0;
//             for(int k=0;k<j;k++)
//             {
//                 mins[i][j] = min(mins[i][j],mins[i][k] + mins[(i+k+1)%n][j-k-1] + getsum(i,j));
//                 maxs[i][j] = max(maxs[i][j],maxs[i][k] + maxs[(i+k+1)%n][j-k-1] + getsum(i,j));
//             }
//         }
//     }
//     minval = mins[0][n-1];
//     maxval = maxs[0][n-1];
//     for(int i=0;i<n;i++)
//     {
//         minval = min(minval,mins[i][n-1]);
//         maxval = max(maxval,maxs[i][n-1]);
//     }
// }
 
// int main()
// {
//     while(scanf("%d",&n)!=EOF)
//     {
//         for(int i=0;i<n;i++)
//             scanf("%d",&a[i]);
//         sum[0] = a[0];
//         for(int i=1;i<n;i++)
//             sum[i] = sum[i-1] + a[i];
//         Work(a,n);
//         printf("%d\n%d\n",minval,maxval);
//     }
//     return 0;
// }