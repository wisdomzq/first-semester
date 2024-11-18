#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int n, a[N], f[N], ans = INT_MAX + 1;
vector <int> G[N];
void dfs(int u, int fa) {
    f[u] = a[u]; // 注意要赋初始值
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == fa) continue;
        dfs(v, u);
        if (f[v] >= 1) f[u] += f[v];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d\n", ans);
}