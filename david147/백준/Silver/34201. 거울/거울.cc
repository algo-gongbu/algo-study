#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long arr[N];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    long long res = 0;
    for (int i = 0; i < (n + 1) / 2; ++i) res += arr[n - 1 - i];
    for (int i = 0; i < n / 2; ++i) res -= arr[i];
    res *= 2;

    if (n % 2) res -= m;
    else res += m;

    cout << res << '\n';

    return 0;
}