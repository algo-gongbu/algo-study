#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int cnt[N + 1], res[N + 1], parent[N + 1];
map<int, int> group[N + 1];

int find(int node) {
    if (node == parent[node]) return node;
    else {
        parent[node] = find(parent[node]);
        return parent[node];
    }
}

void merge(int node1, int node2, int step) {
    if (group[node1].size() < group[node2].size()) swap(node1, node2);
    parent[node2] = node1;
    
    int gameType, numPlayer;
    for (auto& p : group[node2]) {
        gameType = p.first;
        numPlayer = p.second;

        group[node1][gameType] += numPlayer;
        if (group[node1][gameType] == cnt[gameType] && res[gameType] == -1) res[gameType] = step;
    }
    group[node2].clear();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) res[i] = -1;
    
    int temp;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;

        cin >> temp;
        group[i][temp]++;
        cnt[temp]++;
    }

    int a, b;
    for (int i = 1; i <= h; i++) {
        cin >> a >> b;
        if (find(a) == find(b)) continue;
        else merge(find(a), find(b), i);
    }

    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 1) cout << 0 << '\n';
        else cout << res[i] << '\n';
    }

    return 0;
}