#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int ty, tx, dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void f(int sy, int sx) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, 0});

    bool visited[300][300];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }

    int cy, cx, ny, nx, cnt;
    while (!q.empty()) {
        cy = q.front().first.first;
        cx = q.front().first.second;
        cnt = q.front().second;
        q.pop();

        if (cy == ty && cx == tx) {ans = cnt; break;}
        if (visited[cy][cx]) continue;

        visited[cy][cx] = true;
        for (int i = 0; i < 8; ++i) {
            ny = cy + dy[i], nx = cx + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= m) continue;

            if (!visited[ny][nx]) q.push({{ny, nx}, cnt + 1});
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int sy, sx;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        cin >> sy >> sx >> ty >> tx;

        f(sy, sx);
        cout << ans << '\n';
    }

    return 0;
}