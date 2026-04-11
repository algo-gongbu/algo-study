#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
const ll mod = 1000000007;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<ll> acc(n + 1, 0);
    acc[0] = 1;
    for (int i = 1; i <= n; ++i) acc[i] = (acc[i - 1] * 2) % mod;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(all(arr));

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += ((acc[i] - 1) * arr[i]) % mod;
        res %= mod;
        res -= ((acc[n - 1 - i] - 1) * arr[i]) % mod;
        res %= mod;
    }

    cout << (res + mod) % mod << '\n';

    return 0;
}