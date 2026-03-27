#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[101][10][1024];
const ll mod = (ll) 1e9;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= 9; ++i) dp[1][i][1 << i] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 1024; ++j) {
            dp[i][0][j | (1 << 0)] += dp[i - 1][1][j];
            dp[i][0][j | (1 << 0)] %= mod;
        }
        for (int j = 1; j < 9; ++j) {
            for (int k = 0; k < 1024; ++k) {
                dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k];
                dp[i][j][k | (1 << j)] %= mod;
            }
        }
        for (int j = 0; j < 1024; ++j) {
            dp[i][9][j | (1 << 9)] += dp[i - 1][8][j];
            dp[i][9][j | (1 << 9)] %= mod;
        }
    }

    ll res = 0;
    for (int i = 0; i <= 9; ++i) {
        res += dp[n][i][1023];
        res %= mod;
    }

    cout << res << '\n';

    return 0;
}