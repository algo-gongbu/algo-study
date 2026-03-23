#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k, cnt = 0;
	cin >> n >> k;
	vector<bool> primes(n + 1, true);

	for (int i = 2; i <= n; i++) {
		if (!primes[i])
			continue;

		for (int j = i; j <= n; j += i) {
			if (primes[j]) {
				if (++cnt == k) {
					cout << j << "\n";
					return 0;
				}
			}
			primes[j] = false;
		}
	}

	return 0;
}