#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, s, A;
	cin >> N >> s;
	long long ans = 0;

	for (int i = 0; i < (N / 2); i++) {
		cin >> A;
		ans -= (2 * A);
	}

	for (int i = (N / 2); i < N; i++) {
		cin >> A;
		ans += (2 * A);
	}
	if (N % 2 == 0) {
		ans += s;
	}
	else {
		ans -= s;
	}

	cout << ans;

	return 0;
}