#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, time;
};

bool cycle() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<Edge> edges;
    vector<int> dist(n+1,0);
    for (int i=0; i<m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s,e,t});
        edges.push_back({e,s,t});
    }
    for (int i=0; i<w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s,e,-t});
    }
    for (int i=1; i<=n; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.to] > dist[edge.from] + edge.time) {
                dist[edge.to] = dist[edge.from] + edge.time;
                if (i == n) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        if (cycle()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

