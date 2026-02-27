#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int dp[2001], cost[20], people[20];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> cost[i] >> people[i];

    dp[0] = 0;
    for (int i = 1; i <= 2000; i++) {
        dp[i] = INF;
        for (int j = 0; j < m; j++) {
            if (i - people[j] < 0) continue;
            
            if (dp[i] > dp[i - people[j]] + cost[j]) dp[i] = dp[i - people[j]] + cost[j];
        }
    }

    for (int i = n; i <= 2000; i++) {
        // cout << dp[i] << ' ';
        if (minimum > dp[i]) minimum = dp[i];
    }
    // cout << '\n';

    cout << minimum << '\n';

    return 0;
}