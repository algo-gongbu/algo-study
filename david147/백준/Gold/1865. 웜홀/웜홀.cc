#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1 << 24

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int cost[500][500];

void f() {

}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt, start, end, dist;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> n >> m >> h;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (x != y) cost[x][y] = INF;
                else cost[x][y] = 0;
            }
        }

        for (int j = 0; j < m; j++) {
            cin >> start >> end >> dist;
            if (dist < cost[start - 1][end - 1]) cost[start - 1][end - 1] = dist;
            if (dist < cost[end - 1][start - 1]) cost[end - 1][start - 1] = dist;
        }

        for (int j = 0; j < h; j++) {
            cin >> start >> end >> dist;
            if (-dist < cost[start - 1][end - 1]) cost[start - 1][end - 1] = -dist;
        }

        // for (int x = 0; x < n; x++) {   
        //     for (int y = 0; y < n; y++) {
        //         cout << cost[x][y] << ' ';
        //     }
        //     cout << '\n';
        // }

        for (int k = 0; k < n; k++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (cost[x][y] > cost[x][k] + cost[k][y]) cost[x][y] = cost[x][k] + cost[k][y];
                }
            }
        }

        flag = false;
        for (int x = 0; x < n; x++) {
            if (cost[x][x] < 0) {flag = true; break;}
        }
        
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}