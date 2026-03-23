#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e4
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    ll idx = 1;
    for (int i = 0; i < n; ++i) {
        cin >> m >> h;

        idx = 0;
        while ((idx + 1) * (idx + 1) < h - m) ++idx;

        if (idx * idx == h - m) cout << 2 * idx - 1 << '\n';
        else if (idx * idx + idx >= h - m) cout << 2 * idx << '\n';
        else cout << 2 * idx + 1 << '\n';
    }

    return 0;
}