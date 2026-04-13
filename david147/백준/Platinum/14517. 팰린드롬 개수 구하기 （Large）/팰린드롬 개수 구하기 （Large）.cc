#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string text;
    cin >> text;

    vector<vector<int>> dp(text.size(), vector<int>(text.size(), 0));
    for (int i = 0; i < text.size(); ++i) dp[i][i] = 1;
    for (int i = 1; i < text.size(); ++i) {
        for (int j = 0; j < text.size() - i; ++j) {
            dp[j][j + i] = dp[j + 1][j + i] + dp[j][j + i - 1] - dp[j + 1][j + i - 1];
            if (text[j] == text[j + i]) dp[j][j + i] += dp[j + 1][j + i - 1] + 1;
            dp[j][j + i] = (dp[j][j + i] % 10007 + 10007) % 10007;
        }
    }
        
    cout << dp[0][text.size() - 1] << '\n';

    // for (int i = 0; i < text.size(); ++i) {
    //     for (int j = 0; j < text.size(); ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}