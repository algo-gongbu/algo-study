#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

vector<vector<int>> adj(1000000);
int dp[1000000][2];
vector<bool> visited(1000000, false);

void f(int node) {
    visited[node] = true;

    if (!adj[node].size()) {
        dp[node][0] = 0; 
        dp[node][1] = 1; 
        return;
    }

    for (const int& nxt: adj[node]) {
        if (visited[nxt]) continue;

        f(nxt);
        dp[node][0] += dp[nxt][1];
        dp[node][1] += min(dp[nxt][0], dp[nxt][1]);
    }
    dp[node][1] += 1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    f(0);

    cout << min(dp[0][0], dp[0][1]) << '\n';

    return 0;
}