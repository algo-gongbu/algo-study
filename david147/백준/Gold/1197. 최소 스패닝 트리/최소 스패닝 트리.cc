#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e4

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int parent[N + 1], rnk[N + 1];
vector<pair<int, pair<int, int>>> edges;

int find(int node) {
    if (node == parent[node]) return node;
    else {
        parent[node] = find(parent[node]);
        return parent[node];
    }
}

void merge(int node1, int node2) {
    int r1 = find(node1), r2 = find(node2);
    if (r1 == r2) return;
    
    if (rnk[r1] > rnk[r2]) parent[r2] = r1;
    else {
        parent[r1] = r2;
        if (rnk[r1] == rnk[r2]) rnk[r2]++;
    }
}

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rnk[i] = 1;
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    long long res = 0;
    for (int i = 0; i < m; i++) {
        if (find(edges[i].second.first) == find(edges[i].second.second)) continue;

        res += edges[i].first;
        merge(edges[i].second.first, edges[i].second.second);
    }

    cout << res << '\n';
    
    return 0;
}