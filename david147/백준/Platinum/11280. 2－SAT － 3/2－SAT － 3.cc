#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
const int N = 10000;

vector<int> adj[2 * N + 1], rev_adj[2 * N + 1], scc_idx(2 * N + 1);
bool visited[2 * N + 1];
stack<int> s;
vector<vector<int>> sccs;
int n, m;

int to_idx(int x) {
    if (x < 0) return -x + n;
    else return x;
}

int not_idx(int x) {
    if (x <= n) return x + n;
    else return x - n;
}

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
    
    cin >> n >> m;

    int start, end;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end;

        start = to_idx(start); end = to_idx(end);

        adj[not_idx(start)].push_back(end);
        adj[not_idx(end)].push_back(start);
        rev_adj[end].push_back(not_idx(start));
        rev_adj[start].push_back(not_idx(end));
    }

    for (int i = 1; i <= 2 * n; ++i) {
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
            
            for (const auto& elt: scc) scc_idx[elt] = sccs.size();
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (scc_idx[i] == scc_idx[i + n]) {cout << 0 << '\n'; return 0;}
    }

    cout << 1 << '\n';

    return 0;
}