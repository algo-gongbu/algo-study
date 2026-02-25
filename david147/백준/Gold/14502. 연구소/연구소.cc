#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int map[10][10], virus[128], idx, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

void f(int y, int x, int cnt) {
    if (cnt == 0) {
        bool visited[10][10];
        int temp_map[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
                temp_map[i][j] = map[i][j];
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < idx; i += 2) q.push({virus[i], virus[i + 1]});

        int cur_y, cur_x, next_y, next_x;
        while (!q.empty()) {
            cur_y = q.front().first;
            cur_x = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                next_y = cur_y + dy[k];
                next_x = cur_x + dx[k];

                if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) continue;

                if (!visited[next_y][next_x] && temp_map[next_y][next_x] == 0) {
                    temp_map[next_y][next_x] = 2;
                    visited[next_y][next_x] = true;
                    q.push({next_y, next_x});
                }
            }
        }

        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp_map[i][j] == 0) temp++;
                // cout << temp_map[i][j] << ' ';
            }
            // cout << '\n';
        }
        // cout << '\n';
        if (maximum < temp) maximum = temp;
    }    
    else {
        int i = y, j = x;
        if (j == m) {i++; j = 0;}
        while (i < n && j < m) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                f(i, j + 1, cnt - 1);
                map[i][j] = 0;
            }
            j++;
            if (j == m) {i++; j = 0;}
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus[idx++] = i;
                virus[idx++] = j;
            }
        }
    }

    // for (int i = 0; i < idx; i += 2) cout << virus[i] << ' ' << virus[i + 1] << '\n';

    f(0, 0, 3);
    
    cout << maximum << '\n';

    return 0;
}