#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<bool> is_prime(N + 1, true);
vector<ll> prime;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i + i; j <= N; j += i) is_prime[j] = false;
            prime.push_back(i);
        }
    }

    ll n, m;
    cin >> n >> m;
    vector<int> num(m - n + 1, 0);

    ll idx_p = 0, idx_n = 0, sq = prime[0] * prime[0];
    while (idx_p < prime.size() && sq <= m) {
        sq = prime[idx_p] * prime[idx_p];
        idx_n = (n - 1) / sq * sq + sq - n;
        while (idx_n < m - n + 1) {
            ++num[idx_n];
            idx_n += sq;
        }
        ++idx_p;
    }

    for (int i = 0; i < num.size(); ++i) {
        if (num[i] == 0) ++ans;
    }

    cout << ans << '\n';

    return 0;
}