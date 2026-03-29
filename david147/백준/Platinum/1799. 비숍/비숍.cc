#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int board[10][10], n, maximum, res;
vector<bool> f1, f2;

void f(int y, int x, int cnt, bool flag) {
    if (x >= n) {
        y += 1;
        if (flag) {
            if (y % 2) x = 0;
            else x = 1;
        }
        else {
            if (y % 2) x = 1;
            else x = 0;
        }
    }
    if (y == n) {maximum = max(maximum, cnt); return;}

    while (y < n) {
        if (board[y][x] == 1 && !f1[x + y] && !f2[n - x + y]) {
            f1[x + y] = f2[n - x + y] = true;
            f(y, x + 2, cnt + 1, flag);
            f1[x + y] = f2[n - x + y] = false;
        }
        x += 2;
        if (x >= n) {
            y += 1;
            if (flag) {
                if (y % 2) x = 0;
                else x = 1;
            }
            else {
                if (y % 2) x = 1;
                else x = 0;
            }
        }
    }
    maximum = max(cnt, maximum);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    f1.assign(2 * n + 1, false); f2.assign(2 * n + 1, false);
    maximum = 0;
    f(0, 0, 0, false);
    res += maximum;

    f1.assign(2 * n + 1, false); f2.assign(2 * n + 1, false);
    maximum = 0;
    f(0, 1, 0, true);
    res += maximum;

    cout << res << '\n';

    return 0;
}