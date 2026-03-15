#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 4e6
#define mod ((long long) 1e9 + 7)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long fac[N + 1] = { 1, };

long long pow(long long base, long long exp) {
    if (exp == 1) return base;
    
    long long temp = pow(base, exp / 2);
    if (exp % 2 == 0) return (temp * temp) % mod;
    else return (((temp * temp) % mod) * base) % mod;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (fac[i - 1] * i) % mod;
        // cout << fac[i] << ' ';
    }

    long long res = fac[n] * pow((fac[m] * fac[n - m]) % mod, mod - 2);
    cout << res % mod << '\n';

    return 0;
}