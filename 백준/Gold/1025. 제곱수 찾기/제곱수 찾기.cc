#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool is_perfect_square(int n) {
	int root = sqrt(n);
	return pow(root, 2) == n;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, ans = -1;
	string str;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));

	for (int r = 0; r < N; r++) {
		cin >> str;
		for (int c = 0; c < M; c++) {
			v[r][c] = str[c] - '0';
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			
			for (int dr = -N; dr <= N; dr++) {				
				for (int dc = -M; dc <= M; dc++) {
					if (dr == 0 && dc == 0) {
						continue;
					}

					int cur_r = r, cur_c = c, num = 0;

					while (cur_r >= 0 && cur_r < N && cur_c >= 0 && cur_c < M) {
						num = 10 * num + v[cur_r][cur_c];
						cur_r += dr;
						cur_c += dc;

						if (is_perfect_square(num)) {
							ans = max(ans, num);
						}
					}
				}

			}
		}
	}

	cout << ans << "\n";

	return 0;
}