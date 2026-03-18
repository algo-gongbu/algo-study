#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char mapp[100][100];
bool visited[100][100];
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

void f(int start_y, int start_x) {
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;

    int cur_y, cur_x, next_y, next_x;
    while (!q.empty()) {
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            if (next_y >= n || next_y < 0 || next_x >= m || next_x < 0) continue;

            if (!visited[next_y][next_x] && mapp[next_y][next_x] == '#') {
                ++ans;
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int y, x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mapp[i][j];
            if (mapp[i][j] == 'S') {y = i; x = j;}
        }
    }

    f(y, x);

    cout << ++ans << '\n';

    return 0;
}