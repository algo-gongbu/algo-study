#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll left = 1, right = n * n, mid, rb;
    while (left <= right) {
        mid = (left + right) / 2;
        
        rb = 0;
        for (int i = 1; i <= n; ++i) rb += min(n, mid / i);

        if (rb >= m) {ans = mid; right = mid - 1;}
        else left = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}