#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<pair<int, int>> arr[1001];
int dist[1001], prev_city[1001];

void f(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    int temp_start, temp_cost;
    while (!pq.empty()) {
        temp_start = pq.top().second;
        temp_cost = pq.top().first;
        pq.pop();

        if (temp_start == end) return;
        if (dist[temp_start] < temp_cost) continue;

        for (auto next : arr[temp_start]) {
            if (dist[next.first] > dist[temp_start] + next.second) {
                dist[next.first] = dist[temp_start] + next.second;
                prev_city[next.first] = temp_start;
                pq.push({dist[next.first], next.first});
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
    cin >> m;
    int start, end, cost;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        arr[start].push_back({end, cost});
    }

    cin >> start >> end;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[start] = 0;
    f(start, end);

    cout << dist[end] << '\n';
    
    int index = 1, temp = end, city[1000] = { end, };
    while (temp != start) {
        temp = prev_city[temp];
        city[index++] = temp;
    }

    cout << index << '\n';
    while (index > 0) cout << city[--index] << ' ';
    cout << '\n';

    return 0;
}