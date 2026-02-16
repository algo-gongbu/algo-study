#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x, y;
	cin >> T;
	
	while (T--) {
		cin >> x >> y;
		int dist = y - x;
		int max = sqrt(dist);
		int ans;

		if (dist == max * max) {
			ans = 2 * max - 1;
		}
		else if (dist <= (max * max + max)) {
			ans = 2 * max;
		}
		else {
			ans = 2 * max + 1;
		}
		cout << ans << "\n";
	}

	return 0;
}