#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int n, m;
vector<int> arr;
vector<pair<int, int>> adj[8];
map<vector<int>, int> min_dist;

void f(vector<int> start) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    pq.push({0, start});
    min_dist[start] = 0;

    int dist;
    vector<int> cur, temp;
    while (!pq.empty()) {
        cur = pq.top().second;
        dist = pq.top().first;
        pq.pop();

        if (min_dist[cur] < dist) continue;

        for (int i = 0; i < 8; ++i) {
            for (auto& edge: adj[i]) {
                temp = cur;
                swap(temp[i], temp[edge.first]);
                
                if (min_dist.find(temp) == min_dist.end()) {
                    min_dist[temp] = dist + edge.second;
                    pq.push({min_dist[temp], temp});
                }
                else {
                    if (min_dist[temp] > dist + edge.second) {
                        min_dist[temp] = dist + edge.second;
                        pq.push({min_dist[temp], temp});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> m;
    int start, end, c;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end >> c;
        adj[start - 1].push_back({end - 1, c});
        adj[end - 1].push_back({start - 1, c});
    }

    // idea: Dijkstra's algorithm with the entire state of the array as nodes
    f(arr);

    sort(all(arr));
    if (min_dist.find(arr) == min_dist.end()) cout << -1 << '\n';
    else cout << min_dist[arr] << '\n';

    return 0;
}