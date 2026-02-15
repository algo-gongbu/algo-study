#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N, all_visited;
vector<vector<int>> cost, dp;

void input(void) {
	cin >> N;

	all_visited = (1 << N) - 1;
	cost.resize(N, vector<int>(N));
	dp.resize(N, vector<int>((1 << N), -1));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> cost[r][c];
		}
	}
}

int solve(int cur, int visited) {
	if (visited == all_visited) {
		if (cost[cur][0] == 0)
			return INF;
		return cost[cur][0];
	}

	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	dp[cur][visited] = INF;
	for (int next = 1; next < N; next++) {
		if ((visited & (1 << next)) != 0)
			continue;

		if (cost[cur][next] == 0)
			continue;

		int res = solve(next, visited | (1 << next));
		if (res != INF) {
			dp[cur][visited] = min(dp[cur][visited], cost[cur][next] + res);
		}
	}

	return dp[cur][visited];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve(0, (1 << 0));

	return 0;
}