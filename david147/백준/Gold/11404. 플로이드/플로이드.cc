#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1 << 24

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
int cost[100][100];

void f() {

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) cost[i][j] = INF;
        }
    }

    int start, end, dist;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> dist;
        if (dist < cost[start - 1][end - 1]) cost[start - 1][end - 1] = dist;
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] > cost[i][k] + cost[k][j]) cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == INF) cout << 0 << ' ';
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}