#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int parent[3000], rnk[3000], sub_node[3000];

int find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 == n2) return;

    if (rnk[n1] < rnk[n2]) swap(n1, n2);
    parent[n2] = n1;
    sub_node[n1] += sub_node[n2];
    if (rnk[n1] == rnk[n2]) ++rnk[n1];
    
    return;
}

int ccw(int x1, int y1, int x2, int y2) {
    int val = x1 * y2 - x2 * y1;
    if (val > 0) return 1;
    else if (val < 0) return -1;
    else return 0;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> line(n, vector<int>(4));
    for (int i = 0; i < n; ++i) cin >> line[i][0] >> line[i][1] >> line[i][2] >> line[i][3];

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rnk[i] = sub_node[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (find(i) == find(j)) continue;

            int t1 = ccw(line[j][0] - line[i][0], line[j][1] - line[i][1], 
                         line[j][2] - line[i][0], line[j][3] - line[i][1]);
            int t2 = ccw(line[j][0] - line[i][2], line[j][1] - line[i][3], 
                         line[j][2] - line[i][2], line[j][3] - line[i][3]);
            int t3 = ccw(line[i][0] - line[j][0], line[i][1] - line[j][1], 
                         line[i][2] - line[j][0], line[i][3] - line[j][1]);
            int t4 = ccw(line[i][0] - line[j][2], line[i][1] - line[j][3], 
                         line[i][2] - line[j][2], line[i][3] - line[j][3]);

            if (t1 == 0 && t2 == 0) {
                if (min(line[i][0], line[i][2]) <= max(line[j][0], line[j][2]) && 
                    min(line[j][0], line[j][2]) <= max(line[i][0], line[i][2]) &&
                    min(line[i][1], line[i][3]) <= max(line[j][1], line[j][3]) &&
                    min(line[j][1], line[j][3]) <= max(line[i][1], line[i][3])) merge(i, j);
            }
            else if (t1 * t2 <= 0 && t3 * t4 <= 0) merge(i, j);
        }
    }

    int maximum = 0, cnt = 0, idx;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        idx = find(i);
        if (!visited[idx]) {
            visited[idx] = true;
            ++cnt;
            maximum = max(maximum, sub_node[idx]);
        }
    }

    cout << cnt << '\n' << maximum << '\n';

    return 0;
}