#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct e {
	int n;
	int t;

	bool operator< (const e& other) const {
		return t > other.t;
	}
};

int T, n, d, c;
vector<list<e>> adj;
priority_queue<e> pq;
vector<bool> visited;

void input() {
	int a, b, s;
	cin >> n >> d >> c;
	adj.resize(n + 1);
	visited.resize(n + 1, false);

	fill(visited.begin(), visited.end(), false);
	for (int i = 0; i < n + 1; i++) {
		while (!adj[i].empty()) {
			adj[i].pop_back();
		}
	}

	for (int i = 0; i < d; i++) {
		cin >> a >> b >> s;
		adj[b].push_back({ a, s });
	}
}

void solve() {
	int num = 0, t = 0;
	pq.push({ c, 0 });

	while (!pq.empty()) {
		e cur = pq.top();
		pq.pop();

		if (visited[cur.n]) {
			continue;
		}
		visited[cur.n] = true;
		t = cur.t;
		num++;

		for (e next : adj[cur.n]) {
			if (!visited[next.n]) {
				pq.push({ next.n, cur.t + next.t });
			}
		}
	}

	cout << num << " " << t << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		input();
		solve();
	}

	return 0;
}