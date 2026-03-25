#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    int n = s.length();
    int MOD = 10007;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) dp[i][i] = 1;

    for (int len=2; len<=n; len++) {
        for (int i=0; i<=n-len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD;
            }
            else {
                dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD) % MOD;
            }
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}