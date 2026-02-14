#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int cost[800][800];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) cost[i][j] = INF;
        }
    }

    int start, end, dist;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> dist;
        cost[start - 1][end - 1] = dist;
        cost[end - 1][start - 1] = dist;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    cin >> start >> end;
    minimum = min(cost[0][start - 1] + cost[start - 1][end - 1] + cost[end - 1][n - 1], cost[0][end - 1] + cost[end - 1][start - 1] + cost[start - 1][n - 1]);
    if (minimum >= INF) cout << -1 << '\n';
    else cout << minimum << '\n';

    return 0;
}