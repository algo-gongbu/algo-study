#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define ll long long

ll n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
ll x[20], y[20];

void f(int plus, int minus, int idx, ll acc_x, ll acc_y) {
    if (plus > m / 2 || minus > m / 2) return;

    if (plus == m / 2 && minus == m / 2) {
        minimum = min(minimum, acc_x * acc_x + acc_y * acc_y);
        return;
    }
    else {
        f(plus + 1, minus, idx + 1, acc_x + x[idx], acc_y + y[idx]);
        f(plus, minus + 1, idx + 1, acc_x - x[idx], acc_y - y[idx]);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> m;
        for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];

        minimum = LONG_LONG_MAX;
        f(0, 0, 0, 0, 0);

        cout.precision(12);
        cout << sqrt(minimum) << '\n';
    }

    return 0;
}