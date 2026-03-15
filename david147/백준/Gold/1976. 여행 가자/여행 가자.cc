#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 200

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

    int temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            if (temp == 1) merge(i, j);
        }
    }

    int start;
    cin >> start;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (find(start) != find(temp)) {flag = true; break;}
    }

    if (flag) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}