#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 5e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int parent[N + 1], rnk[N + 1];

int find(int node) {
    if (node == parent[node]) return node;
    
    parent[node] = find(parent[node]);
    return parent[node];
}

void merge(int node1, int node2) {
    int r1 = find(node1), r2 = find(node2);

    if (r1 == r2) return; 

    if (rnk[r1] < rnk[r2]) swap(r1, r2);
    parent[r2] = r1;
    if (rnk[r1] == rnk[r2]) rnk[r1]++;
}

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 1;
    }    

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (find(a) == find(b)) {ans = i; break;}
        else merge(a, b);
    }

    cout << ans << '\n';

    return 0;
}