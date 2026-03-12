#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 3e4

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int parent[N + 1], rnk[N + 1], num[N + 1], candy[N + 1], dp[N + 1][3000];
vector<pair<int, int>> group;

int find(int node) {
    if (node == parent[node]) return node;
    else {
        parent[node] = find(parent[node]);
        return parent[node];
    }
}

void merge(int node1, int node2) {
    if (rnk[node1] < rnk[node2]) swap(node1, node2);
    parent[node2] = node1;
    num[node1] += num[node2];
    num[node2] = 0;
    candy[node1] += candy[node2];
    if (rnk[node1] == rnk[node2]) ++rnk[node1];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 1; i <= n; ++i) cin >> candy[i];

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rnk[i] = num[i] = 1;
    }

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (find(a) == find(b)) continue;
        else merge(find(a), find(b));
    }

    for (int i = 1; i <= n; ++i) {
        if (num[i]) group.push_back({num[i], candy[i]});
    }

    // for (int i = 0; i < group.size(); ++i) {
    //     cout << group[i].first << ' ' << group[i].second << '\n';
    // }

    for (int i = 1; i <= group.size(); ++i) {
        for (int j = 1; j < h; ++j) {
            if (group[i - 1].first > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - group[i - 1].first] + group[i - 1].second);
        }
    }

    cout << dp[group.size()][h - 1] << '\n';

    return 0;
}