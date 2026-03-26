#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct point {
	int r;
	int c;
	int t;
};

int H, W, N;
vector<vector<char>> board;
vector<vector<bool>> visited;
queue<point> q;
point start_p;

point drc[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

void input() {
	string str;
	cin >> H >> W >> N;
	board.resize(H, vector<char>(W));
	visited.resize(H, vector<bool>(W, false));

	for (int r = 0; r < H; r++) {
		cin >> str;
		for (int c = 0; c < W; c++) {
			board[r][c] = str[c];
			if (str[c] == 'S') {
				start_p = { r, c, 0 };
			}
		}
	}
}

int solve() {
	int hp = 1;
	q.push(start_p);
	visited[start_p.r][start_p.c] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		for (point d_ : drc) {
			point next = { cur.r + d_.r, cur.c + d_.c, cur.t + 1 };
			if (!(0 <= next.r && next.r < H && 0 <= next.c && next.c < W))
				continue;

			if (visited[next.r][next.c])
				continue;

			if ('1' <= board[next.r][next.c] && board[next.r][next.c] <= '9') {
				if (hp == (board[next.r][next.c] - '0')) {
					if (++hp == N + 1) {
						return next.t;
					}
					while (!q.empty()) {
						q.pop();
					}
					q.push(next);

					for (int r = 0; r < H; r++) {
						fill(visited[r].begin(), visited[r].end(), false);
					}
					visited[next.r][next.c] = true;
					break;
				}
				else {
					q.push(next);
					visited[next.r][next.c] = true;
				}
			}
			else if (board[next.r][next.c] != 'X') {
				q.push(next);
				visited[next.r][next.c] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	cout << solve() << "\n";

	return 0;
}