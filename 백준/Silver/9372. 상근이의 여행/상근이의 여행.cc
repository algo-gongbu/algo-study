#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N, M, a, b;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int m = 0; m < M; m++) {
			cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}

	return 0;
}