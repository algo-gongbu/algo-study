#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

ll EEA(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1; y = 0; return a;}

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
    
    ll n, a;
    cin >> n >> a;
    cout << n - a << ' ';

    ll x, y;
    if (EEA(a, n, x, y) == 1) cout << (x + n) % n << '\n';
    else cout << -1 << '\n';
    
    return 0;
}