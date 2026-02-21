#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[100001], dp[100001];

void f() {
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        // cout << dp[i] << ' ';
        if (maximum < dp[i]) maximum = dp[i];
    }
    // cout << '\n';
    
    cout << maximum << '\n';

    return 0;
}