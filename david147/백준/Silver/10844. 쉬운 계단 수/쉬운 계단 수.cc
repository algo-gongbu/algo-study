#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int dp[100][10], mod = 1e9;

void f() {
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= 9; i++) dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1] % mod;
        for (int j = 1; j < 9; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        dp[i][9] = dp[i - 1][8] % mod;
    }

    for (int i = 0; i <= 9; i++) {
        ans += dp[n - 1][i];
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}