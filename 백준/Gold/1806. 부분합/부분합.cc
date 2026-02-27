#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[100000];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = 0, sum = 0;
    while (right < n) {
        while (right < n && sum < m) sum += arr[right++];
        if (sum < m) break;
        while (left < n && sum >= m) sum -= arr[left++];
        if (minimum > right - left + 1) minimum = right - left + 1;
    }

    if (minimum == INT_MAX) cout << 0 << '\n';
    else cout << minimum << '\n';

    return 0;
}