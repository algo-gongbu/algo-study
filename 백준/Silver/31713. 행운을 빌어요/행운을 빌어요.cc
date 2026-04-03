#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, A, B;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> A >> B;
	
		if (B < 3 * A) {
			cout << 3 * A - B;
		}
		else if (B <= 4 * A) {
			cout << 0;
		}
		else { // B > 4 * A
			int A_ = ceil(B / 4.0);
			if (3 * A_ <= B) {
				cout << A_ - A;
			}
			else {
				cout << (A_ - A) + (3 * A_ - B);
			}
		}

		cout << "\n";
	}

	return 0;
}