#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int parent[100000], rnk[100000];

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
    if (rnk[n1] == rnk[n2]) ++rnk[n1];
    
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rnk[i] = 1;
    }
    
    vector<pair<int, int>> x(n), y(n), z(n);
    int tx, ty, tz;
    for (int i = 0; i < n; ++i) {
        cin >> tx >> ty >> tz;
        x[i] = {tx, i}, y[i] = {ty, i}, z[i] = {tz, i};
    }
    sort(all(x)); sort(all(y)); sort(all(z));

    vector<pair<int, pair<int, int>>> edge;
    for (int i = 0; i < n - 1; ++i) {
        edge.push_back({x[i + 1].first - x[i].first, {x[i + 1].second, x[i].second}});
        edge.push_back({y[i + 1].first - y[i].first, {y[i + 1].second, y[i].second}});
        edge.push_back({z[i + 1].first - z[i].first, {z[i + 1].second, z[i].second}});
    }
    sort(all(edge));

    int a, b;
    ll res = 0;
    for (int i = 0; i < edge.size(); ++i) {
        a = edge[i].second.first, b = edge[i].second.second;
        if (find(a) == find(b)) continue;
        else {
            res += (ll) edge[i].first;
            merge(a, b);
        }
    }

    cout << res << '\n';

    return 0;
}