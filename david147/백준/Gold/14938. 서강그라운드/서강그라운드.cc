#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int item[100];
int dist[100][100];

void f() {
    
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 0; i < n; i++) cin >> item[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) dist[i][j] = INF;
        }
    }

    int start, end, cost;
    for (int i = 0; i < h; i++) {
        cin >> start >> end >> cost;
        dist[start - 1][end - 1] = dist[end - 1][start - 1] = cost;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= m) ans += item[j];
        }
        if (maximum < ans) maximum = ans;
    }

    cout << maximum << '\n';

    return 0;
}