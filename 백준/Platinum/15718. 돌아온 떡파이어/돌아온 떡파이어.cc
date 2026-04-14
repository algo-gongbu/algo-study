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
        else return (val * val) % mod;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll p[2] = {97, 1031};
    vector<vector<ll>> fac(2, vector<ll>(1031, 1));
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < p[i]; ++j) fac[i][j] = (fac[i][j - 1] * j) % p[i];
    }

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
    
        if (m == 1) {
            if (n == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }
        else if (n < m - 1) {cout << 0 << '\n'; continue;}

        ll res = 0;
        for (int i = 0; i < 2; ++i) {
            ll nn = n - 1, mm = m - 2, val = 1, rn, rm;
            
            while (nn && mm) {
                rn = nn % p[i], rm = mm % p[i];

                if (rn < rm) {
                    val = 0;
                    break;
                }

                if (rn != 0) {
                    val *= (fac[i][rn] * power((fac[i][rn - rm] * fac[i][rm]) % p[i], p[i] - 2, p[i])) % p[i];
                    val %= p[i];
                }

                nn /= p[i], mm /= p[i];
            }
            
            val *= 100007 / p[i];
            val %= 100007;
            val *= power(100007 / p[i], p[i] - 2, p[i]);
            val %= 100007;

            res += val;
            res %= 100007;
        }

        cout << res << '\n';
    }

    return 0;
}