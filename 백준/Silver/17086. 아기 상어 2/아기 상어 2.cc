#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
	int r;
	int c;
	int d;
};

int N, M;
vector<vector<bool>> board;
vector<vector<bool>> visited;
queue<point> q;

point drc[8] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };

void init_visited() {
	for (int r = 0; r < N; r++) {
		fill(visited[r].begin(), visited[r].end(), false);
	}
}

bool is_valid(point p) {
	return 0 <= p.r && p.r < N && 0 <= p.c && p.c < M;
}

int bfs(point src) {
	if (board[src.r][src.c])
		return 0;

	init_visited();
	visited[src.r][src.c] = true;
	q.push({ src.r, src.c, 0 });

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (point d_ : drc) {
			point next = { cur.r + d_.r, cur.c + d_.c, cur.d + 1 };
			if (!is_valid(next) || visited[next.r][next.c]) {
				continue;
			}

			if (board[next.r][next.c]) {
				while (!q.empty()) {
					q.pop();
				}
				return next.d;
			}
			else {
				visited[next.r][next.c] = true;
				q.push(next);
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int max_ = -1, in;
	cin >> N >> M;
	board.resize(N, vector<bool>(M));
	visited.resize(N, vector<bool>(M, false));

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> in;
			if (in == 0) {
				board[r][c] = false;
			}
			else {
				board[r][c] = true;
			}
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			max_ = max(max_, bfs({r, c}));
		}
	}
	cout << max_;

	return 0;
}