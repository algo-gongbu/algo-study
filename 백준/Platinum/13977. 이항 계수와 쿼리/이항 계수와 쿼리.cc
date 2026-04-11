#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
const ll mod = 1000000007;

ll power(ll base, ll exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return base % mod;
    else {
        ll val = power(base, exp / 2);
        if (exp & 1) return (((val * val) % mod) * base) % mod;
        else return (val * val) % mod;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<ll> fac(4000001);
    fac[0] = 1;
    for (int i = 1; i <= 4000000; ++i) fac[i] = (fac[i - 1] * i) % mod;

    int m;
    cin >> m;

    int n, k;
    while (m--) {
        cin >> n >> k;
        cout << (fac[n] * power((fac[k] * fac[n - k]) % mod, mod - 2)) % mod << '\n';
    }

    return 0;
}