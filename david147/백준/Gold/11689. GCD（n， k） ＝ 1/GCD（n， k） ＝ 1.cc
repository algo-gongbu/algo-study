#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

ll power(ll base, ll exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return base;
    else {
        ll val = power(base, exp / 2);
        if (exp % 2) return val * val * base;
        else return val * val;
    }
}

vector<bool> is_prime(1000000, true);
vector<ll> prime;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 2; i < 1000000; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i + i; j < 1000000; j += i) is_prime[j] = false;
        }
    }

    ll n;
    cin >> n;

    vector<pair<ll, ll>> pe_pair;
    for (const ll& p : prime) {
        ll cnt = 0;
        while (n % p == 0) {cnt++; n /= p;}
        
        if (cnt > 0) pe_pair.push_back({p, cnt});
    }
    
    if (n > 1) pe_pair.push_back({n, 1});
    
    ll ans = 1;
    for (const auto& elt: pe_pair) {
        ans *= (elt.first - 1) * power(elt.first, elt.second - 1);
    }
    cout << ans << '\n';

    return 0;
}