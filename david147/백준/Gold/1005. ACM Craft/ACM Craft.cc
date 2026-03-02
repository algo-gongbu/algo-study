#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> graph[N + 1];
int cost[N + 1], memo[N + 1];

int f(int cur) {
    if (graph[cur].size() == 0) return cost[cur];

    int local_max = INT_MIN;
    for (auto temp : graph[cur]) {
        if (memo[temp] == -1) memo[temp] = f(temp);
        if (local_max < memo[temp]) local_max = memo[temp];
    }

    return local_max + cost[cur];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h;
    int pre, post, target;
    for (int i = 0; i < h; i++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> cost[i];

        for (int i = 1; i <= n; i++) graph[i].clear();

        for (int i = 1; i <= m; i++) {
            cin >> pre >> post;
            graph[post].push_back(pre);
        }

        cin >> target;

        for (int i = 1; i <= n; i++) memo[i] = -1;

        cout << f(target) << '\n';
    }
    
    return 0;
}