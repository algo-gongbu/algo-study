#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ans = -1;
	cin >> N;
	vector<int> v(N), lis(N, 1), lis_rev(N, 1);

	for (int n = 0; n < N; n++) {
		cin >> v[n];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (v[j] < v[i]) {
				lis_rev[i] = max(lis_rev[i], lis_rev[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, lis[i] + lis_rev[i] - 1);
	}
	cout << ans << "\n";

	return 0;
}