#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
map<string, int> group;
int parent[N + 1], rnk[N + 1], sub_node[N + 1], idx = 1;

int find(int node) {
    if (node == parent[node]) return node;
    else {
        parent[node] = find(parent[node]);
        return parent[node];
    }
}

void merge(int node1, int node2) {
    if (node1 == node2) {cout << sub_node[node1] << '\n'; return;}

    if (rnk[node1] < rnk[node2]) swap(node1, node2);
    parent[node2] = node1;
    if (rnk[node1] == rnk[node2]) rnk[node1]++;
    
    sub_node[node1] += sub_node[node2];
    cout << sub_node[node1] << '\n';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        group.clear();
        idx = 1;

        cin >> m;
        for (int j = 1; j <= 2 * m; j++) {
            parent[j] = j;
            rnk[j] = sub_node[j] = 1;
        }

        for (int j = 0; j < m; j++) {
            cin >> s1 >> s2;
            if (group.find(s1) == group.end()) group[s1] = idx++;
            if (group.find(s2) == group.end()) group[s2] = idx++;      
            // cout << group[s1] << group[s2] << '\n';
            
            merge(find(group[s1]), find(group[s2]));
        }
    }

    return 0;
}