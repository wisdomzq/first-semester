#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int, int>> teleports;
char maze[2010][2010];
bool visit[2010][2010];
int dis[2010][2010];
int n, m;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // 四个方向

bool judge(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m && maze[x][y] != 'M') return true;
    return false;
}

int bfs(int x1, int y1, int x2, int y2) {
    // 初始化距离数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dis[i][j] = 1e9;  // 初始化为一个很大的数
        }
    }

    queue<pair<int, int>> q;
    q.push({x1, y1});
    dis[x1][y1] = 0;
    visit[x1][y1] = true;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if (now.first == x2 && now.second == y2) return dis[x2][y2];

        // 尝试四个方向移动
        for (int i = 0; i < 4; i++) {
            int x = now.first + dir[i][0];
            int y = now.second + dir[i][1];
            int t = dis[now.first][now.second] + 1;

            if (judge(x, y) && !visit[x][y]) {
                visit[x][y] = true;
                dis[x][y] = t;
                q.push({x, y});
            }
        }

        // 处理传送点
        if (maze[now.first][now.second] == 'E') {
            for (auto teleport : teleports) {
                int x = teleport.first;
                int y = teleport.second;

                if (!visit[x][y]) {
                    visit[x][y] = true;
                    dis[x][y] = dis[now.first][now.second];  // 传送不增加距离
                    q.push({x, y});
                }
            }
        }
    }

    return -1;  // 如果没有找到食物
}

int main() {
    cin >> n >> m;
    int startx, starty, endx, endy;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            maze[i][j + 1] = s[j];
            if (maze[i][j + 1] == 'N') startx = i, starty = j + 1;
            else if (maze[i][j + 1] == 'C') endx = i, endy = j + 1;
            else if (maze[i][j + 1] == 'E') teleports.push_back({i, j + 1});
        }
    }

    memset(visit, false, sizeof(visit));

    int result = bfs(startx, starty, endx, endy);
    if (result == -1) {
        cout << "Bad Eureka" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
