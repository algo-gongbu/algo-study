#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[100001][301];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    const int mod = 998244353, thr = 300;
    
    for (int i = 1; i <= 300; ++i) dp[0][i] = 1;

    for (int i = 1; i <= 100000; ++i) {
        for (int j = 1; j <= 300; ++j) {
            if (i >= j) dp[i][j] = (dp[i - j][j] * i) % mod;
            else dp[i][j] = i % mod;
        }
    }

    int q, n, k;
    cin >> q;
    while (q--) {
        cin >> n >> k;

        if (k <= thr) cout << dp[n][k] << '\n';
        else {
            ll res = 1;
            while (n > 0) {
                res *= n;
                res %= mod;
                n -= k;
            }
            cout << res << '\n';
        }
    }

    return 0;
}