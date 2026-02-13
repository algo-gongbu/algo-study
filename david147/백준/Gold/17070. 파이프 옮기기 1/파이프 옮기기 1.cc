#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
int house[16][16];

void f() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 1}, 0});

    int x, y, direction;
    while (!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        direction = q.front().second;
        q.pop();

        if (y == n - 1 && x == n - 1) {
            ans += 1;
            continue;
        }

        if (direction == 0) {
            if (x + 1 < n && house[y][x + 1] == 0) {
                q.push({{y, x + 1}, 0});
            }

            if (x + 1 < n && y + 1 < n && house[y + 1][x + 1] == 0 && house[y][x + 1] == 0 && house[y + 1][x] == 0) {
                q.push({{y + 1, x + 1}, 2});
            }
        }
        else if (direction == 1) {
            if (y + 1 < n && house[y + 1][x] == 0) {
                q.push({{y + 1, x}, 1});
            }

            if (x + 1 < n && y + 1 < n && house[y + 1][x + 1] == 0 && house[y][x + 1] == 0 && house[y + 1][x] == 0) {
                q.push({{y + 1, x + 1}, 2});
            }
        }
        else {
            if (x + 1 < n && house[y][x + 1] == 0) {
                q.push({{y, x + 1}, 0});
            }

            if (y + 1 < n && house[y + 1][x] == 0) {
                q.push({{y + 1, x}, 1});
            }

            if (x + 1 < n && y + 1 < n && house[y + 1][x + 1] == 0 && house[y][x + 1] == 0 && house[y + 1][x] == 0) {
                q.push({{y + 1, x + 1}, 2});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> house[i][j];
        }
    }

    f();
    
    cout << ans << '\n';

    return 0;
}