#include <iostream>
#define MAX 5000

using namespace std;

int c_u, c_d, c_p, d_u, d_d, d_p, H;

bool hunt_success(int t) {
	int remaining_hp = H - (t / c_u + 1) * d_u - (t / c_d + 1) * d_d - (t / c_p + 1) * d_p;
	return remaining_hp <= 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> c_u >> d_u >> c_d >> d_d >> c_p >> d_p >> H;

	int lo = 0, ho = MAX;
	while (lo < ho) {
		int mid = (lo + ho) / 2;
		if (hunt_success(mid)) {
			ho = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << lo;

	return 0;
}