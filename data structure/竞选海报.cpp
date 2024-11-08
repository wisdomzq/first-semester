// #include <iostream>
// #include <vector>
// #include <set>
// using namespace std;

// const int MAXN = 10000005;
// int l[MAXN], r[MAXN];
// vector<int> tree(4 * MAXN, 0);
// vector<int> lazy(4 * MAXN, 0);
// set<int> visible;

// void push_down(int node, int start, int end) {
//     if (lazy[node] != 0) {
//         tree[node] = lazy[node];
//         if (start != end) {
//             lazy[node * 2] = lazy[node];
//             lazy[node * 2 + 1] = lazy[node];
//         }
//         lazy[node] = 0;
//     }
// }

// void update(int node, int start, int end, int L, int R, int value) {
//     push_down(node, start, end);
//     if (start > R || end < L) return;
//     if (start >= L && end <= R) {
//         lazy[node] = value;
//         push_down(node, start, end);
//         return;
//     }
//     int mid = (start + end) / 2;
//     update(node * 2, start, mid, L, R, value);
//     update(node * 2 + 1, mid + 1, end, L, R, value);
// }

// void query(int node, int start, int end) {
//     push_down(node, start, end);
//     if (start == end) {
//         if (tree[node] != 0) visible.insert(tree[node]);
//         return;
//     }
//     int mid = (start + end) / 2;
//     query(node * 2, start, mid);
//     query(node * 2 + 1, mid + 1, end);
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n; i++) {
//             cin >> l[i] >> r[i];
//         }
//         fill(tree.begin(), tree.end(), 0);
//         fill(lazy.begin(), lazy.end(), 0);
//         visible.clear();
//         for (int i = 1; i <= n; i++) {
//             update(1, 1, MAXN, l[i], r[i], i);
//         }
//         query(1, 1, MAXN);
//         cout << visible.size() << endl;
//     }
//     return 0;
// }
#include<iostream>
#include<cstring>
using namespace std;
bool vis[10005];
int n,m,ans,A[10005],B[10005];
void Solve(int a,int b,int now,int num)
{
    if(vis[num]) return;//Warning 2
    while(now<=m&&(a>=B[now]||b<=A[now])) now++;
    if(now>m) ans++,vis[num]=1;
    if(a<A[now]&&A[now]<b) Solve(a,A[now],now+1,num); 
    if(b>B[now]&&B[now]>a) Solve(B[now],b,now+1,num);
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
    cin>>m;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;i++) 
	{
		cin>>A[i]>>B[i];
		B[i]++;
	}
    for(int i=m-1;i>=1;i--) Solve(A[i],B[i],i+1,i);
    cout<<ans+1<<endl;
    ans=0;
    }
    
}