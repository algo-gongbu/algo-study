#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> dp(N + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}

	cout << dp[N] << "\n";

	return 0;
}