#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int map[20][20], visited[20][20], cur_size = 2, dy[4] = {-1, 0, 0, 1}, dx[4] = {0, -1, 1, 0};

void f(int y, int x, int food) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = INF;
        }
    }
    visited[y][x] = 0;

    int cur_y, cur_x, cnt, next_y, next_x, target_y = INF, target_x = INF, target_time = INF;
    flag = false;
    while (!q.empty()) {
        cur_y = q.front().first.first;
        cur_x = q.front().first.second;
        cnt = q.front().second;
        q.pop();

        if (target_time < cnt) {
            // cout << target_y << ' ' << target_x << ' ' << target_time << '\n';
            // for (int q = 0; q < n; q++) {
            //     for (int p = 0; p < n; p++) {
            //         cout << map[q][p] << ' ';
            //     }
            //     cout << '\n';
            // }
            break;
        }

        if (map[cur_y][cur_x] > 0 && map[cur_y][cur_x] < cur_size) {
            flag = true;
            target_time = cnt;
            
            if ((target_y > cur_y) || (target_y == cur_y && target_x > cur_x)) {
                target_y = cur_y;
                target_x = cur_x;
            }
        }

        for (int i = 0; i < 4; i++) {
            next_y = cur_y + dy[i];
            next_x = cur_x + dx[i];

            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;

            if (visited[next_y][next_x] == INF && map[next_y][next_x] <= cur_size) {
                visited[next_y][next_x] = cnt + 1;
                q.push({{next_y, next_x}, cnt + 1});
            }
        }
    }

    if (flag) {
        ans += target_time;
        food--;
        if (food == 0) {cur_size++; food = cur_size;}
        map[target_y][target_x] = 0;
    }

    if (target_time != INF) f(target_y, target_x, food);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int start_y, start_x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {start_y = i; start_x = j; map[i][j] = 0;}
        }
    }

    f(start_y, start_x, cur_size);

    cout << ans << '\n';

    return 0;
}