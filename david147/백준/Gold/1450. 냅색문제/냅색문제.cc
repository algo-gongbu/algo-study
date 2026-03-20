#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 30
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
ll arr[N];
vector<ll> half1, half2;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int size;
    half1.push_back(0);
    for (int i = 0; i < n / 2; ++i) {
        size = half1.size();
        for (int j = 0; j < size; ++j) half1.push_back(half1[j] + arr[i]);
    }
    sort(half1.begin(), half1.end());

    half2.push_back(0);
    for (int i = n / 2; i < n; ++i) {
        size = half2.size();
        for (int j = 0; j < size; ++j) half2.push_back(half2[j] + arr[i]);
    }
    sort(half2.begin(), half2.end());

    ll left = 0, right = half2.size() - 1, val, idx;
    while (left < half1.size() && right >= 0) {
        val = half1[left] + half2[right];

        if (val > m) --right;
        else if (val <= m) {++left; ans += right + 1;}
    }

    cout << ans << '\n';

    return 0;
}