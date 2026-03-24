#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<bool> is_prime(2000, true), visited(25, false);
vector<int> arr, even, odd, res, match(25, -1);
vector<vector<int>> adj(25);

bool bm(int node) { // bipartite matching
    for (const int& nxt : adj[node]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;

        if (match[nxt] == -1 || bm(match[nxt])) {
            match[nxt] = node;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 2; i < 2000; ++i) {
        if (is_prime[i]) {
            for (int j = i + i; j < 2000; j += i) is_prime[j] = false;
        }
    }

    cin >> n;
    bool is_odd = false;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        
        if (i == 0) {
            if (m % 2) is_odd = true;
        }

        if (m % 2) odd.push_back(m);
        else even.push_back(m);
    }

    if (odd.size() != even.size()) {cout << -1 << '\n'; return 0;}

    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            if (is_odd) {
                if (is_prime[odd[i] + even[j]]) adj[i].push_back(j);
            }
            else {
                if (is_prime[even[i] + odd[j]]) adj[i].push_back(j);
            }
        }
    }

    for (const int& elt : adj[0]) {
        match.assign(n / 2, -1);
        match[elt] = 0;

        flag = true;
         for (int i = 1; i < n / 2; ++i) {
            visited.assign(n / 2, false);
            visited[elt] = true;
            
            if (!bm(i)) {flag = false; break;}
        }

        if (flag) {
            if (is_odd) res.push_back(even[elt]);
            else res.push_back(odd[elt]);
        }
    }
    
    if (res.size()) {
        sort(res.begin(), res.end());
        for (const int& elt : res) cout << elt << ' ';
        cout << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}