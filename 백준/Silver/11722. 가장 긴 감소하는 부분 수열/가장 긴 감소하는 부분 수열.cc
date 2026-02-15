#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v, dp;

void input() {
	cin >> N;
	dp.resize(N, 1);
	v.resize(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];
}

int solve() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve();

	return 0;
}