#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 4e6
#define ll (long long)
// #define mod (ll 1e9 + 7)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long a, b, c, fac[2000] = { 1, };

long long power(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    else if (exp == 1) return base % mod;
    
    long long temp = power(base, exp / 2, mod);
    if (exp % 2 == 0) return (temp * temp) % mod;
    else return (((temp * temp) % mod) * base) % mod;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    for (int i = 1; i <= c; ++i) fac[i] = (fac[i - 1] * i) % c;
    
    long long r1, r2, res = 1;
    while (a && b) {
        r1 = a % c, r2 = b % c;
        // cout << r1 << ' ' << r2 << '\n';
        if (r1 < r2) {res = 0; break;}
        
        if (r1 != 0) {
            res *= (fac[r1] * power((fac[r2] * fac[r1 - r2]) % c, c - 2, c)) % c;
            res %= c;
        }
        a /= c; b /= c;
    }

    cout << res << '\n';

    return 0;
}