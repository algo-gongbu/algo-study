#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 200

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[1000][3], temp[3], dp[1000][3];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n ;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) temp[j] = arr[0][j];
        for (int j = 0; j < 3; j++) {
            if (i != j) arr[0][j] = INF;
            dp[0][j] = arr[0][j];
        }

        for (int j = 1; j < n; j++) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + arr[j][2];
        }

        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (minimum > dp[n - 1][j]) minimum = dp[n - 1][j];
        }

        for (int j = 0; j < 3; j++) arr[0][j] = temp[j];
    }

    cout << minimum << '\n';

    return 0;
}