#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
#define pii pair<int, int>

using namespace std;

int bfs(int src, int dst);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	cout << bfs(N, K);

	return 0;
}

int bfs(int src, int dst) {
	queue<pii> q;
	vector<bool> visited(MAX, false);

	q.push({ src, 0 });
	visited[src] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		if (cur.first == dst)
			return cur.second;

		if (cur.first - 1 >= 0 && !visited[cur.first - 1]) {
			q.push({ cur.first - 1, cur.second + 1 });
			visited[cur.first - 1] = true;
		}

		if (cur.first + 1 < MAX && !visited[cur.first + 1]) {
			q.push({ cur.first + 1, cur.second + 1 });
			visited[cur.first + 1] = true;
		}

		if (2 * cur.first < MAX && !visited[2 * cur.first]) {
			q.push({ 2 * cur.first, cur.second + 1 });
			visited[2 * cur.first] = true;
		}
	}

	return -1;
}