#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

ll power(ll base, ll exp, ll mod) {
    if (exp == 0) return 1;
    else if (exp == 1) return base % mod;
    else {
        ll val = power(base, exp / 2, mod);
        if (exp & 1) return (((val * val) % mod) * base) % mod;
        return (val * val) % mod;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll m, s, x1, x2;
    cin >> m >> s >> x1 >> x2;

    ll inv = power(((x1 - s) % m + m) % m, m - 2, m);
    ll a = (((x2 - x1) * inv) % m + m) % m;
    ll c = ((x1 - a * s) % m + m) % m;

    cout << a << ' ' << c << '\n';

    return 0;
}