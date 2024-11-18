#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int score[305], fa[305];
bool vis[305];
int f[305][305];
int head[305], edge_len;
struct Edge {
    int to;
    int next;
} edges[605];
void add(int from, int to) {//加边
    edges[++edge_len].to = to;
    edges[edge_len].next = head[from];
    head[from] = edge_len;
}
void dfs(int x) {
    f[x][1] = score[x];
    int to;
    for (int i = head[x]; ~i; i = edges[i].next) { // 遍历 x 的所有子节点
        to = edges[i].to; // to 是 x 的一个子节点
        dfs(to); // 计算 to 节点的 f 数组
        for (int j = m; j >= 1; j--)//倒序枚举，使用 to 节点的 f 数组更新 x 节点的 f 数组
            for (int i = j - 1; i >= 1; i--)
                f[x][j] = max(f[x][j], f[x][j - i] + f[to][i]);
    }
}
int main() {

    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &fa[i], &score[i]);
        add(fa[i], i);//由父节点指向子节点的单向边
    }
    m++; // 由于 0 号节点的参与，m 需要自加1
    dfs(0);//搜索 0 号节点
    cout << f[0][m];
    return 0;
}