#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> tree[100000];
int nodes[100000];
bool visited[100000];

int f(int root) {
    int sum = 1;
    for (auto next : tree[root]) {
        if (visited[next]) continue;

        visited[next] = true;
        if (!nodes[next]) nodes[next] = f(next);
        sum += nodes[next];
    }
    return sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    int start, end;
    for (int i = 0; i < n - 1; i++) {
        cin >> start >> end;
        tree[start - 1].push_back(end - 1);
        tree[end - 1].push_back(start - 1);
    }

    visited[m - 1] = true;
    nodes[m - 1] = f(m - 1);

    int temp;
    for (int i = 0; i < h; i++) {
        cin >> temp;
        cout << nodes[temp - 1] << '\n';
    }

    return 0;
}