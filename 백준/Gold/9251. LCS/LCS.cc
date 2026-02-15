#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s1, s2;
vector<vector<int>> dp;

void input(void) {
	cin >> s1 >> s2;
	dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, 0));
}

int solve(void) {
	int s1_size = s1.size(), s2_size = s2.size();

	for (int r = 1; r <= s1_size; r++) {
		for (int c = 1; c <= s2_size; c++) {
			if (s1[r - 1] == s2[c - 1]) {
				dp[r][c] = dp[r - 1][c - 1] + 1;
			}
			else {
				dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
			}
		}
	}
	return dp[s1_size][s2_size];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve();

	return 0;
}