#include <iostream>
#include <vector>
#define MAX 301

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	vector<int> scores(N, 0);
	vector<int> dp(N, 0);
	
	for (int n = 0; n < N; n++) {
		cin >> scores[n];
	}

	dp[0] = scores[0];
	dp[1] = scores[0] + scores[1];
	dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]);
	
	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
	}

	cout << dp[N - 1] << "\n";

	return 0;
}