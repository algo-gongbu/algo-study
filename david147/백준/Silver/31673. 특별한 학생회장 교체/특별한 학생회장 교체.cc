#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m, temp, total = 0, idx = 0;
    priority_queue<ll> pq;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        total += temp;
        pq.push(temp);
    }

    ll ans;
    temp = 0;
    while (!pq.empty()) {
        temp += pq.top();
        pq.pop();
        ++idx;
        if (total - temp <= temp) {ans = m / (idx + 1); break;}
    }

    cout << ans << '\n';

    return 0;
}