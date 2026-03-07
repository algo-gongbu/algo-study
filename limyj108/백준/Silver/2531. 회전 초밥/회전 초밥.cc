#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, d, k, c;
vector<int> sushi;

void input() {
	cin >> N >> d >> k >> c;
	sushi.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
}

int solve() {
	vector<int> type(d + 1, 0);
	int ans = -1, cnt = 0;
	
	for (int i = 0; i < k; i++) {
		if (type[sushi[i]] == 0) {
			cnt++;
		}
		type[sushi[i]]++;
	}

	ans = cnt + (type[c] == 0 ? 1 : 0);

	for (int i = 1; i < N; i++) {
		int out = i - 1, in = (i + k - 1) % N;
		
		type[sushi[out]]--;
		if (type[sushi[out]] == 0) {
			cnt--;
		}

		type[sushi[in]]++;
		if (type[sushi[in]] == 1) {
			cnt++;
		}

		ans = max(ans, cnt + ((type[c] == 0) ? 1 : 0));
		
		if (ans == k + 1)
			return ans;
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve() << "\n";

	return 0;
}