#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long acc[N + 1], mod = (long long) 1e9 + 7;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) acc[i] = acc[i - 1] + i;
    long long res = 0, cnt = 1;
    for (long long i = 1; i <= n; i++) {
        res += (i * (2 * acc[i]) % mod) % mod;
        res %= mod;
        cnt *= (i * i) % mod;
        cnt %= mod;
    }

    cout << res << ' ' << cnt << '\n';

    return 0;
}