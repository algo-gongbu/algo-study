#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
const int N = 10000;

vector<int> adj[N + 1], rev_adj[N + 1];
bool visited[N + 1];
stack<int> s;
vector<vector<int>> sccs;

void dfs1(int cur) {
    visited[cur] = true;
    
    for (const int& nxt: adj[cur]) {
        if (!visited[nxt]) dfs1(nxt);
    }

    s.push(cur);
}

void dfs2(int cur, vector<int>& scc) {
    visited[cur] = true;
    scc.push_back(cur);

    for (const int& nxt: rev_adj[cur]) {
        if (!visited[nxt]) dfs2(nxt, scc);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int start, end;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end;
        adj[start].push_back(end);
        rev_adj[end].push_back(start);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs1(i);
    }

    memset(visited, false, sizeof(visited));

    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (!visited[cur]) {
            vector<int> scc;
            dfs2(cur, scc);
            sort(all(scc));
            sccs.push_back(scc);    
        }
    }

    sort(all(sccs));
    cout << sccs.size() << '\n';
    for (int i = 0; i < sccs.size(); ++i) {
        for (int j = 0; j < sccs[i].size(); ++j) cout << sccs[i][j] << ' ';
        cout << -1 << '\n';
    }

    return 0;
}