#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e4

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long dp[N + 1];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[0] = dp[2] = 1;
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; j < i / 2 - 1; j++) {
            dp[i] += (2 * dp[i - 2 - j] * dp[j]);
            dp[i] %= 987654321;
        } 
        dp[i] += (dp[i / 2 - 1] * dp[i / 2 - 1]);
        dp[i] %= 987654321;
    }
    
    cout << dp[n] << '\n';

    return 0;
}