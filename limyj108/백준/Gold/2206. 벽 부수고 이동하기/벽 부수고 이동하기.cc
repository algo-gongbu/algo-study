#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct point {
	int r;
	int c;
	int dist;
	int broke; //0: 벽 안부숨, 1: 벽 부숨
};

int N, M;
point drc[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<int>> board;
vector<vector<vector<bool>>> visited;
queue<point> q;

void input() {
	string row;
	cin >> N >> M;
	board.resize(N + 1, vector<int>(M + 1));
	visited.resize(N + 1, vector<vector<bool>>(M + 1, vector<bool>(2, false)));

	for (int r = 1; r <= N; r++) {
		cin >> row;

		for (int c = 1; c <= M; c++) {
			board[r][c] = row[c - 1] - '0';
		}
	}
}

bool is_valid(point p) {
	return 1 <= p.r && p.r <= N && 1 <= p.c && p.c <= M;
}

int bfs(point dst) {
	q.push({ 1, 1, 1, false });
	visited[1][1][0] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.r == dst.r && cur.c == dst.c)
			return cur.dist;

		for (point d : drc) {
			point next = { cur.r + d.r, cur.c + d.c, cur.dist + 1};
			
			if (is_valid(next)) {
				if (board[next.r][next.c] == 1) {
					if (cur.broke == 0 && !visited[next.r][next.c][1]) {
						next.broke = 1;
						visited[next.r][next.c][1] = true;
						q.push(next);
					}
				}
				else {
					if (!visited[next.r][next.c][cur.broke]) {
						next.broke = cur.broke;
						visited[next.r][next.c][next.broke] = true;
						q.push(next);
					}
				}
			}	
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << bfs({ N, M }) << "\n";

	return 0;
}