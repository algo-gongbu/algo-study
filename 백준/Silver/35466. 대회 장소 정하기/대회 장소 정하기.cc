#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, a, b, c, p, q, r;
	cin >> N >> a >> b >> c >> p >> q;

	int u_ = 0, d_ = a, p_, x_;
	int p1 = a + b, p2 = (a - b + N) % N;

	if (min(p1, N - p1) == c) {
		p_ = p1;
	}
	else {
		p_ = p2;
	}

	int u1 = p, u2 = (N - p) % N, d1 = a + q, d2 = (a - q + N) % N;
	if (u1 == d1 || u1 == d2) {
		x_ = u1;
	}
	else {
		x_ = u2;
	}

	r = min(abs(p_ - x_), N - abs(p_ - x_));
	cout << r << "\n";

	return 0;
}