#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 4e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int a[N], b[N], c[N], d[N];
vector<int> arr;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr.push_back(c[i] + d[j]);
        }
    }

    sort(arr.begin(), arr.end());

    long long res = 0;
    int cur, left, right, mid, temp_idx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cur = -(a[i] + b[j]);

            auto lb = lower_bound(arr.begin(), arr.end(), cur);
            auto rb = upper_bound(arr.begin(), arr.end(), cur);

            res += rb - lb;
        }
    }

    cout << res << '\n';

    return 0;
}