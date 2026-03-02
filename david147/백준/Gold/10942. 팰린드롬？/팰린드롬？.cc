#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[N];
bool dp[N][N];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0][0] = true;
    for (int i = 1; i < n; i++) {
        dp[i][i] = true;
        if (arr[i - 1] == arr[i]) dp[i - 1][i] = true;
        for (int j = i - 2; j >= 0; j--) {
            if (arr[j] == arr[i]) dp[j][i] = dp[j + 1][i - 1];
        }
    }

    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (dp[a - 1][b - 1]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    
    return 0;
}