#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int visited[100001];

void f() {
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 0;

    int pos, time;
    while (!q.empty()) {
        pos = q.front().first;
        time = q.front().second;
        q.pop();
        // cout << pos << '\n' << time << '\n';

        if (visited[pos] < time) continue;

        if (minimum == time) {
            if (pos == m) { ans++; continue; }
        }
        else if (minimum > time) {
            if (pos == m) { minimum = time; ans = 1; continue; }

            if (pos - 1 >= 0) {
                if (visited[pos - 1] >= time + 1) {
                    visited[pos - 1] = time + 1;
                    q.push({pos - 1, time + 1});
                }
            }

            if (pos + 1 <= 100000) {
                if (visited[pos + 1] >= time + 1) {
                    visited[pos + 1] = time + 1;
                    q.push({pos + 1, time + 1});
                }
            }

            if ((pos << 1) <= 100000) {
                if (visited[pos << 1] >= time + 1) {
                    visited[pos << 1] = time + 1;
                    q.push({pos << 1, time + 1});
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

    cin >> n >> m;
    
    for (int i = 0; i <= 100000; i++) visited[i] = INF;

    f();

    cout << minimum << '\n' << ans << '\n';

    return 0;
}