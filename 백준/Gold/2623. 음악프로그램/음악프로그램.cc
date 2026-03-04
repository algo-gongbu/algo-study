#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 32e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<vector<int>> adj(N + 1);
vector<int> in_deg(N + 1, 0), res;

void f() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) q.push(i);
    }

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (auto temp : adj[cur]) {
            if (--in_deg[temp] == 0) q.push(temp);
        }

        res.push_back(cur);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    int order[100];
    for (int i = 0; i < m; i++) {
        cin >> h;
        for (int j = 0; j < h; j++) cin >> order[j];

        for (int j = 0; j < h - 1; j++) {
            adj[order[j]].push_back(order[j + 1]);
            in_deg[order[j + 1]]++;
        }
    }

    f();

    if (res.size() < n) cout << 0 << '\n';
    else {
        for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';
    }

    return 0;
}