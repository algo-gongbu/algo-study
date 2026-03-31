#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

vector<bool> is_prime(10000000, true);
vector<ll> prime;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 2; i < 10000000; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i + i; j < 10000000; j += i) is_prime[j] = false;
        }
    }

    ll a, b;
    cin >> a >> b;

    ll res = 0;
    for (const ll& p: prime) {
        if (p * p > b) break;

        ll temp = b / p / p;
        while (temp) {
            ++res;
            temp /= p;
        }
    }

    a -= 1;
    for (const ll& p: prime) {
        if (p * p > a) break;

        ll temp = a / p / p;
        while (temp) {
            --res;
            temp /= p;
        }
    }

    cout << res << '\n';

    return 0;
}