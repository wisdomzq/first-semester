// #include<iostream>
// #include<queue>
// #include<vector>
// #include<cstring>
// #include<string>
// using namespace std;
// int n,m;
// struct node{
//     int num;
//     string name;
// };
// struct Node{
//     int end,dis;
// };
// char s[5005];
// int du[5005];
// vector<node> G;//记录节点信息
// vector<Node> G2[5005];//记录边信息
// vector<int> ans;
// bool judge=true;
// void Topo_sort()
// {
//     priority_queue<int, vector<int>, greater<int>> q; // 使用小顶堆优先队列
//     int processed = 0; // 记录已处理的节点数量
//     for(int i=0;i<n;i++)
//     {
//         if(du[i]==0)
//         {
//             q.push(i);
//         }
//     }
//     while(!q.empty())
//     {
//         int now=q.top();
//         q.pop();
//         if(du[now]==0) 
//         {
//            ans.push_back(now);
//            processed++; // 更新已处理节点数
//         }
//         for(int i=0;i<G2[now].size();i++)
//         {
//             int next=G2[now][i].end;
//             du[next]--;
//             if(du[next]==0)
//             {
//                 q.push(next);
//             }
//         }
//     }
//       // 判断是否无法构成拓扑排序
//     if(processed < n)
//     {
//         judge = false; // 存在环，无法拓扑排序
//     }
//     else
//     {
//         judge = true; // 可以进行拓扑排序
//     }
// }
// int main()
// {
//     char op;
//     cin>>n>>op>>m;
//     cin>>s;
//     int cnt=0;
//     int l,r,w;
//     int len=strlen(s);
//     for(int i=0;i<len;i++)
//     {
//         string tmp;
//         while(s[i]!=','&&s[i]!='\0')
//         {
//             tmp+=s[i];
//             i++;
//         }
//         node t;
//         t.num=cnt++;
//         t.name=tmp;
//         G.push_back(t);
//     }
//     for(int i=1;i<m;i++)
//     {
//         cin>>op>>l>>op>>r>>op>>w>>op>>op;
//         G2[l].push_back({r,w});
//         du[r]++;
//     }
//     cin>>op>>l>>op>>r>>op>>w>>op;
//         G2[l].push_back({r,w});
//         du[r]++;
//     Topo_sort();
//     if(judge)
//     {
//         for(int i=0;i<ans.size();i++)
//         {
//             cout<<G[ans[i]].name;
//             if(i!=ans.size()-1) cout<<"-";
//         }
//         cout<<endl;
        
//     }
//     else cout<<"NO TOPOLOGICAL PATH"<<endl;
// }
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

struct node {
    int num;
    string name;
};

struct Edge {
    int end, dis;
};

char s[5005];
int du[5005];
vector<node> G;            // 记录节点信息
vector<Edge> G2[5005];     // 记录边信息
vector<int> ans;           // 拓扑排序结果
bool judge = true;

// 新增的全局变量
vector<int> ve;            // 事件的最早发生时间
vector<int> vl;            // 事件的最晚发生时间
vector<int> criticalG[5005];   // 关键路径的邻接表
vector<vector<int>> criticalPaths; // 存储所有关键路径
vector<int> path;          // 当前路径

void Topo_sort() {
    priority_queue<int, vector<int>, greater<int>> q; // 使用小顶堆优先队列
    int processed = 0; // 记录已处理的节点数量
    for(int i = 0; i < n; i++) {
        if(du[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.top();
        q.pop();
        if(du[now] == 0) {
            ans.push_back(now);
            processed++; // 更新已处理节点数
        }
        for(int i = 0; i < G2[now].size(); i++) {
            int next = G2[now][i].end;
            du[next]--;
            if(du[next] == 0) {
                q.push(next);
            }
        }
    }
    // 判断是否无法构成拓扑排序
    if(processed < n) {
        judge = false; // 存在环，无法拓扑排序
    } else {
        judge = true; // 可以进行拓扑排序
    }
}

// 深度优先搜索查找所有关键路径
void dfs_critical(int u) {
    if(u == n - 1) {
        // 到达终点，保存当前路径
        criticalPaths.push_back(path);
        return;
    }
    for(int i = 0; i < criticalG[u].size(); i++) {
        int v = criticalG[u][i];
        path.push_back(v);
        dfs_critical(v);
        path.pop_back();
    }
}

int main() {
    char op;
    cin >> n >> op >> m;
    cin >> s;
    int cnt = 0;
    int l, r, w;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        string tmp;
        while(s[i] != ',' && s[i] != '\0') {
            tmp += s[i];
            i++;
        }
        node t;
        t.num = cnt++;
        t.name = tmp;
        G.push_back(t);
    }
    // 初始化入度数组
    memset(du, 0, sizeof(du));
    for(int i = 1; i < m; i++) {
        cin >> op >> l >> op >> r >> op >> w >> op >> op;
        G2[l].push_back({r, w});
        du[r]++;
    }
    // 读入最后一条边
    cin >> op >> l >> op >> r >> op >> w >> op;
    G2[l].push_back({r, w});
    du[r]++;
    
    Topo_sort();

    if(judge) {
        // 输出拓扑排序结果
        for(int i = 0; i < ans.size(); i++) {
            cout << G[ans[i]].name;
            if(i != ans.size() - 1) cout << "-";
        }
        cout << endl;

        // 初始化 ve 和 vl 数组
        ve.resize(n, 0);
        vl.resize(n, 0);
        // 计算事件的最早发生时间 ve，即点的最长路径
        //按照拓扑排序的顺序计算事件的最早发生时间 ve，对所有后继事件 v，有 ve[u] + w <= ve[v]，其中(u, v)∈E
        //ve[u] = max{ve[v] + w}，其中(u, v)∈E
        for(int i = 0; i < ans.size(); ++i) {
            int u = ans[i];
            for(int j = 0; j < G2[u].size(); ++j) {
                int v = G2[u][j].end;
                int w = G2[u][j].dis;
                if(ve[u] + w > ve[v]) {
                    ve[v] = ve[u] + w;
                }
            }
        }
        // 项目总工期
        int projectDuration = ve[ans.back()];
        // 初始化 vl 数组，终点的 vl 等于项目总工期
        for(int i = 0; i < n; ++i) {
            vl[i] = projectDuration;
        }
        // 计算事件的最晚发生时间 vl，表示事件（顶点）最迟必须开始的时间，以不延误项目的最早完成时间为前提
        //逆拓扑排序的顺序计算事件的最晚发生时间 vl，对所有前驱事件 u，有 vl[v] - w >= vl[u]，其中(u, v)∈E
        for(int i = ans.size() - 1; i >= 0; --i) {
            int u = ans[i];
            for(int j = 0; j < G2[u].size(); ++j) {
                int v = G2[u][j].end;
                int w = G2[u][j].dis;
                if(vl[v] - w < vl[u]) {
                    vl[u] = vl[v] - w;
                }
            }
        }
        // 构建关键路径的邻接表 criticalG
        //关键活动是指在活动的最早开始时间和最晚开始时间之间没有时间余地的活动，即这些活动的拖延会直接影响项目的总工期。
        //条件：ve[u] == vl[v] - w
        for(int u = 0; u < n; ++u) {
            for(int j = 0; j < G2[u].size(); ++j) {
                int v = G2[u][j].end;
                int w = G2[u][j].dis;
                if(ve[u] == vl[v] - w) {
                    criticalG[u].push_back(v);
                }
            }
        }
        // 从起点开始深度优先搜索所有关键路径
        path.clear();
        criticalPaths.clear();
        path.push_back(0);
        dfs_critical(0);
        // 对所有关键路径进行排序
        sort(criticalPaths.begin(), criticalPaths.end(), [](const vector<int>& a, const vector<int>& b) {
            // 按节点名称的字典序排序
            for(size_t i = 0; i < min(a.size(), b.size()); ++i) {
                if(G[a[i]].name != G[b[i]].name) {
                    return G[a[i]].name < G[b[i]].name;
                }
            }
            return a.size() < b.size();
        });
        // 输出所有关键路径
        for(const auto& cp : criticalPaths) {
            for(size_t i = 0; i < cp.size(); ++i) {
                cout << G[cp[i]].name;
                if(i != cp.size() - 1) cout << "-";
            }
            cout << endl;
        }
    }
    else {
        cout << "NO TOPOLOGICAL PATH" << endl;
    }
    return 0;
}