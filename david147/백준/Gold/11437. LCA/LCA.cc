#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

const int N = 50000;
vector<vector<int>> adj(N + 1);
vector<bool> visited(N + 1);
vector<int> parent(N + 1), depth(N + 1);

void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;

    for (const int& nxt: adj[node]) {
        if (visited[nxt]) continue;

        parent[nxt] = node;
        dfs(nxt, d + 1);
    }
}

int lca(int node1, int node2) {
    if (depth[node1] < depth[node2]) swap(node1, node2);

    while (depth[node1] > depth[node2]) node1 = parent[node1];

    while (node1 != node2) {
        node1 = parent[node1];
        node2 = parent[node2];
    }

    return node1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int start, end;
    for (int i = 0; i < n - 1; ++i) {
        cin >> start >> end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    dfs(1, 0);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> start >> end;
        cout << lca(start, end) << '\n';
    }

    return 0;
}