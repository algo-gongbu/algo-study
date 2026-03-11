#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long x[4], y[4];

int ccw(int i, int j, int base) {
    long long temp = (x[i] - x[base]) * (y[j] - y[base]) - (x[j] - x[base]) * (y[i] - y[base]);
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; ++i) cin >> x[i] >> y[i];

    int v1 = ccw(2, 3, 0), v2 = ccw(2, 3, 1), v3 = ccw(0, 1, 2), v4 = ccw(0, 1, 3);
    if (v1 == 0 && v2 == 0) {
        if (min(x[0], x[1]) <= max(x[2], x[3]) && min(x[2], x[3]) <= max(x[0], x[1]) && 
            min(y[0], y[1]) <= max(y[2], y[3]) && min(y[2], y[3]) <= max(y[0], y[1])) cout << 1 << '\n';
        else cout << 0 << '\n';
        return 0;
    }

    if (v1 * v2 <= 0 && v3 * v4 <= 0) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}