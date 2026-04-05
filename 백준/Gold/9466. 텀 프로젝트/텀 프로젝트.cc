#include <iostream>
#include <vector>
#include <list>

using namespace std;
/*
	0: Unvisited
	1: Visiting (아직 postvisit 안 함)
	2: Visited/Finished (postvisit 완료)

	탐색 중 Visiting 상태인 node 발견 
	-> ancestor로의 edge (back edge) 존재
	-> cycle 존재
*/

enum {
	UNVISITED, VISITING, VISITED
};

int T, n, num;
void dfs(int src, vector<int>& adj, vector<int>& visited, vector<bool>& team);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> n;
		int ans = 0;
		vector<int> adj(n + 1);
		vector<int> visited(n + 1, UNVISITED);
		vector<bool> team(n + 1, false);

		for (int i = 1; i <= n; i++) {
			cin >> num;
			adj[i] = num;
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == UNVISITED) {
				dfs(i, adj, visited, team);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!team[i]) {
				ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

void dfs(int src, vector<int>& adj, vector<int>& visited, vector<bool>& team) {
	visited[src] = VISITING;
	
	if (visited[adj[src]] == VISITING) { // back edge
		int s = adj[src];
		team[s] = true;

		while (s != src) {
			s = adj[s];
			team[s] = true;
		}
	}
	else if (visited[adj[src]] == UNVISITED) {
		dfs(adj[src], adj, visited, team);
	}

	visited[src] = VISITED;
}