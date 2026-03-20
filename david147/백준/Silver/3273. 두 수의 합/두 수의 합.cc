#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[N];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> m;

    sort(arr, arr + n);

    int left = 0, right = n - 1, sum;
    while (left < right) {
        sum = arr[left] + arr[right];
        
        if (sum > m) --right;
        else if (sum < m) ++left;
        else {++ans; ++left;}
    }

    cout << ans << '\n';

    return 0;
}