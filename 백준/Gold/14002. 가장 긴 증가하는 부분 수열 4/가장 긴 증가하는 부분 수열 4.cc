#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[N + 1], dp[N + 1], pre[N + 1];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
    }

    int idx;
    for (int i = 1; i <= n; ++i) {
        if (maximum < dp[i]) {
            maximum = dp[i];
            idx = i;
        }
    }
    
    cout << maximum + 1 << '\n';

    set<int> res;
    while (idx != 0) {
        res.insert(res.end(), arr[idx]);
        idx = pre[idx];
    }
    
    for (int elt : res) cout << elt << ' ';
    cout << '\n';

    return 0;
}