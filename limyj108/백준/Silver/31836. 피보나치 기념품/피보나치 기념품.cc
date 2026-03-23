#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	if (N % 3 == 0 || N % 3 == 1) {
		int X = N / 3, Y = 2 * (N / 3);
		cout << X << "\n";

		for (int n = N; n >= 3; n -= 3) {
			cout << n << " ";
		}

		cout << "\n" << Y << "\n";
		for (int n = N; n >= 3; n -= 3) {
			cout << n - 1 << " " << n - 2 << " ";
		}
	}
	else {
		int X = N / 3 + 1, Y = 2 * (N / 3) + 1;
		cout << X << "\n";

		for (int n = N; n >= 3; n -= 3) {
			cout << n << " ";
		}
		cout << 2 << "\n";

		cout << Y << "\n";
		for (int n = N; n >= 3; n -= 3) {
			cout << n - 1 << " " << n - 2 << " ";
		}
		cout << 1 << "\n";
	}

	return 0;
}