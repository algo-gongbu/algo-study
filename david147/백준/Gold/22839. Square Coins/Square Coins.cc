#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> coin, dp(301, 0);
    for (int i = 1; i <= 17; ++i) coin.push_back(i * i);
    
    dp[0] = 1;
    for (int i = 0; i < 17; ++i) {
        for (int j = 1; j < 301; ++j) {
            if (j >= coin[i]) dp[j] += dp[j - coin[i]];
        }
    }

    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        else cout << dp[n] << '\n';
    }

    return 0;
}