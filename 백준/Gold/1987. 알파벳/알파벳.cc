#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char map[20][20];
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

int count(int n) { // brian kernighan's algorithm
    int cnt = 0;
    while (n) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

void f() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1 << (map[0][0] - 'A')});

    int y, x, flag, next_x, next_y, temp;
    while (!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        flag = q.front().second;
        q.pop();
        
        temp = count(flag);
        if (temp > maximum) maximum = temp;

        for (int i = 0; i < 4; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];

            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

            temp = map[next_y][next_x] - 'A';
            if ((flag & (1 << temp)) == 0) {
                q.push({{next_y, next_x}, flag ^ (1 << temp)});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    f();

    cout << maximum << '\n';

    return 0;
}