#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1510;
vector<int> tree[MAXN];
int dp[MAXN][2];//状态0：该节点未放置士兵。
//状态1：该节点放置了士兵
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int i = 0; i < tree[u].size(); ++i) {
        int v = tree[u][i];
        if (!visited[v]) {
            dfs(v);
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            tree[i].clear();
        }
        memset(dp, 0, sizeof(dp));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; ++i) {
            int u, k;
            char ch;
            cin >> u >> ch >>ch>> k >> ch;
            for (int j = 0; j < k; ++j) {
                int v;
                cin >> v;
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
        }
        dfs(0);
        int ans = min(dp[0][0], dp[0][1]);
        cout << ans << endl;
    }
    return 0;
}
