#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
const ll mod = 10007;

ll power(int base, int exp) {
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
    
    int n;
    cin >> n;
    
    vector<ll> fac(53, 0);
    fac[0] = 1;
    for (int i = 1; i <= 52; ++i) fac[i] = (fac[i - 1] * i) % mod;    

    ll res = 0;
    for (int i = 1; i <= n / 4; ++i) {
        ll t1 = (fac[13] * power(fac[13 - i] * fac[i], mod - 2)) % mod;
        ll t2 = (fac[52 - 4 * i] * power(fac[n - 4 * i] * fac[52 - n], mod - 2)) % mod;

        if (i & 1) res += (t1 * t2) % mod;
        else res -= (t1 * t2) % mod;
    }

    cout << (res % mod + mod) % mod << '\n';

    return 0;
}