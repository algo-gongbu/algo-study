#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int map[50][50], purifier[2], dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

void f() {
    int temp[50][50] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] < 5) continue;
            else {
                int cnt = 0, part = map[i][j] / 5, y, x;
                for (int k = 0; k < 4; k++) {
                    y = i + dy[k];
                    x = j + dx[k];

                    if (x < 0 || x >= m || y < 0 || y >= n) continue;

                    if (x == 0 && (y == purifier[0] || y == purifier[1])) continue;

                    temp[y][x] += part;
                    cnt++;
                }
                map[i][j] -= part * cnt;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] += temp[i][j];
        }
    }

    map[purifier[0] - 1][0] = -1;
    for (int i = purifier[0]; i > 0; i--) map[i][0] = map[i - 1][0];
    for (int i = 0; i < m - 1; i++) map[0][i] = map[0][i + 1];
    for (int i = 0; i < purifier[0]; i++) map[i][m - 1] = map[i + 1][m - 1];
    for (int i = m - 1; i > 0; i--) map[purifier[0]][i] = map[purifier[0]][i - 1];
    map[purifier[0]][1] = 0;

    map[purifier[1] + 1][0] = -1;
    for (int i = purifier[1]; i < n - 1; i++) map[i][0] = map[i + 1][0];
    for (int i = 0; i < m - 1; i++) map[n - 1][i] = map[n - 1][i + 1];
    for (int i = n - 1; i > purifier[1]; i--) map[i][m - 1] = map[i - 1][m - 1];
    for (int i = m - 1; i > 0; i--) map[purifier[1]][i] = map[purifier[1]][i - 1];
    map[purifier[1]][1] = 0;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    int index_p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) purifier[index_p++] = i;
        }
    }

    for (int i = 0; i < h; i++) f();

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += map[i][j];
        }
    }

    cout << ans + 2 << '\n';

    return 0;
}