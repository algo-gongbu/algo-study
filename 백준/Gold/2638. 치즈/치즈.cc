#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int map[100][100], cheese[20000], dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

void f() {
    bool visited[100][100];
    int temp_map[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            temp_map[i][j] = map[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int cur_y, cur_x, next_y, next_x;
    while (!q.empty()) {
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue;

            if (!visited[next_y][next_x] && temp_map[next_y][next_x] == 0) {
                visited[next_y][next_x] = true;
                temp_map[next_y][next_x] = -1;
                q.push({next_y, next_x});
            }
        }
    }

    int idx = 0, cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp_map[i][j] == 1) {
                cnt = 0;
                for (int k = 0; k < 4; k++) {
                    next_y = i + dy[k];
                    next_x = j + dx[k];

                    if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue;

                    if (temp_map[next_y][next_x] == -1) cnt++;
                }
                if (cnt >= 2) {
                    cheese[idx++] = i;
                    cheese[idx++] = j;
                }
            }
        }
    }

    for (int i = 0; i < idx; i += 2) {map[cheese[i]][cheese[i + 1]] = 0;}
    h -= idx / 2;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) h++;
        }
    }

    while (h != 0) {
        f();
        ans++;
    }

    cout << ans << '\n';
    
    return 0;
}