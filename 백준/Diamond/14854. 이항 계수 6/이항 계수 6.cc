#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define ll long long
// #define mod (ll 1e9 + 7)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long a, b, c, fac[N + 1] = { 1, };
vector<bool> is_prime(N + 1, true);
vector<ll> prime, except_p;
vector<pair<ll, ll>> p_i;

long long power(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    else if (exp == 1) return base % mod;
    
    long long temp = power(base, exp / 2, mod);
    if (exp % 2 == 0) return (temp * temp) % mod;
    else return (((temp * temp) % mod) * base) % mod;
}

ll legendre(ll n, ll p) {
    ll cnt = 0;
    while (n) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}

ll product_excp(ll n, ll p, ll pk) {
    ll res = 1;
    while (n) {
        if ((n / pk) % 2 == 1) res *= -1;
        res *= except_p[n % pk];
        res %= pk;
        n /= p;
    }

    if (res < 0) res += pk;

    return res;
}

ll EEA(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1, y = 0; return a;}

    ll xx, yy;
    ll gcd = EEA(b, a % b, xx, yy);

    x = yy;
    y = xx - (a / b) * yy;

    return gcd;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= N; j += i) is_prime[j] = false;
        }
    }

    cin >> h;
    ll n, k, m = 142857;

    long long cnt = 0, temp = m;
    for (int i = 0; i < prime.size(); ++i) {     
        cnt = 0;   
        while (temp % prime[i] == 0) {
            temp /= prime[i];
            ++cnt;
        }

        if (cnt > 0) p_i.push_back({prime[i], cnt});
        if (temp == 1) break;
    }

    // for (int i = 0; i < p_i.size(); ++i) {
    //     cout << p_i[i].first << ' ' << p_i[i].second << '\n';
    // }

    ll cur_p, cur_e, temp_exp, pk, a, b, c, gcd, x, y, res;
    for (int i = 0; i < h; ++i) {
        cin >> n >> k;

        res = 0;
        for (int j = 0; j < p_i.size(); ++j) {
            cur_p = p_i[j].first, cur_e = p_i[j].second;
            temp_exp = legendre(n, cur_p) - legendre(k, cur_p) - legendre(n - k, cur_p);
            if (temp_exp >= cur_e) continue;

            pk = power(cur_p, cur_e, (ll) 1e9);
            except_p.assign(pk, 1);
            for (int l = 1; l < pk; ++l) {
                if (l % cur_p != 0) except_p[l] = (except_p[l - 1] * l) % pk;
                else except_p[l] = except_p[l - 1];
            } 
            
            a = product_excp(n, cur_p, pk), b = product_excp(k, cur_p, pk), c = product_excp(n - k, cur_p, pk);
            if (EEA(b * c, pk, x, y) == 1) {
                temp = (((power(cur_p, temp_exp, pk) * a) % pk) * ((x % pk + pk) % pk)) % pk;
            }
            if (EEA(m / pk, pk, x, y) == 1) {
                res += (((temp * (m / pk)) % m) * ((x % pk + pk) % pk)) % m;
            }
            res %= m;
            except_p.clear();
        }

        cout << res << '\n';
    }

    
    return 0;
}