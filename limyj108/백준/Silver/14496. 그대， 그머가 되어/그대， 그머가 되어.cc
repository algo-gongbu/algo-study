#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>

using namespace std;

int bfs(vector<vector<int>>& v, vector<bool>& visited, int src, int dst);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, N, M, x, y;
	cin >> a >> b >> N >> M;
	vector<bool> visited(N + 1, false);
	vector<vector<int>> v(N + 1);

	for (int m = 0; m < M; m++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << bfs(v, visited, a, b);

	return 0;
}

int bfs(vector<vector<int>>& v, vector<bool>& visited, int src, int dst) {
	queue<pii> q;
	q.push({src, 0});
	visited[src] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if (cur.first == dst) {
			return cur.second;
		}

		for (int next : v[cur.first]) {
			if (!visited[next]) {
				q.push({ next, cur.second + 1 });
				visited[next] = true;
			}
		}
	}

	return -1;
}