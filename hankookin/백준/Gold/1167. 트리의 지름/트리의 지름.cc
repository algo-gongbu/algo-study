#include "bits/stdc++.h"
using namespace std;

vector<pair<int,int>> adj[100001];
bool visited[100001];
int maxDist = 0;
int farNode = 0;

void dfs(int curr, int dist) {
    visited[curr] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farNode = curr;
    }
    for (int i=0; i<adj[curr].size(); i++) {
        int nextNode = adj[curr][i].first;
        int nextWeight = adj[curr][i].second;

        if (!visited[nextNode]) dfs(nextNode, dist+nextWeight);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    


    for (int i=0; i<n; i++) {
        int u, v, w;
        cin >> u;
        while (true) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[u].push_back({v,w});
        }
    }
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(farNode, 0);

    cout << maxDist << "\n";
    
    return 0;
}