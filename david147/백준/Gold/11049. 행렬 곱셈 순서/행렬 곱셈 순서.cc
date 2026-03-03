#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 5e2

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int mat[N + 1];
int dp[N][N];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> mat[0];
    for (int i = 1; i < n; i++) cin >> mat[i] >> m;
    cin >> mat[n];

    int local_min, temp;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0 ;j--) {
            local_min = INT_MAX;
            for (int k = j; k < i; k++) {
                temp = dp[j][k] + dp[k + 1][i] + mat[j] * mat[k + 1] * mat[i + 1];
                if (local_min > temp) local_min = temp;
            }
            dp[j][i] = local_min;
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;
}