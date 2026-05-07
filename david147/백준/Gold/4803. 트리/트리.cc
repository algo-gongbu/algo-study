#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

bool dfs(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[node] = true;

    bool is_tree = true;
    for (const int& nxt: adj[node]) {
        if (nxt == parent) continue;

        if (visited[nxt]) is_tree = false;
        else is_tree = dfs(nxt, node, visited, adj) && is_tree;
    }

    return is_tree;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int idx = 1;
    while (1) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        vector<vector<int>> adj(n + 1);
        int start, end;
        for (int i = 0; i < m; ++i) {
            cin >> start >> end;
            adj[start].push_back(end);
            adj[end].push_back(start);
        }

        vector<bool> visited(n + 1, false);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;

            if (dfs(i, 0, visited, adj)) ++cnt;
        }

        if (cnt == 0) cout << "Case " << idx++ << ": No trees.\n";
        else if (cnt == 1) cout << "Case " << idx++ << ": There is one tree.\n";
        else cout << "Case " << idx++ << ": A forest of " << cnt << " trees.\n";       
    }

    return 0;
}