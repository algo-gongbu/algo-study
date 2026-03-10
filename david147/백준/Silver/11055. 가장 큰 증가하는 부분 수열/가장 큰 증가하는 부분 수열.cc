#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[N], dp[N];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += arr[i];
    }
    
    for (int i = 0; i < n; i++) maximum = max(maximum, dp[i]);

    cout << maximum << '\n';

    return 0;
}