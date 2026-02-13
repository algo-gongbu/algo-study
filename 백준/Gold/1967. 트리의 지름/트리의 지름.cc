#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF INT_MAX

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
vector<pair<int, int>> graph[10000];
int start;

void f() {
    bool visited[10000] = { false };
    int cost[10000] = { 0 };
    queue<int> q;
    q.push({start});
    visited[start] = true;

    int node, dist;
    while (!q.empty()) {
        node = q.front();
        q.pop();

        if (maximum < cost[node]) { maximum = cost[node]; start = node; }

        for (auto next : graph[node]) {
            if (!visited[next.first]) {
                visited[next.first] = true;
                if (cost[next.first] < cost[node] + next.second) {
                    cost[next.first] = cost[node] + next.second;
                    q.push(next.first);
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int parent, child, dist;
    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child >> dist;
        graph[parent - 1].push_back({child - 1, dist});
        graph[child - 1].push_back({parent - 1, dist});
    }

    f();
    f();
    
    cout << maximum << "\n";
    
    return 0;
}