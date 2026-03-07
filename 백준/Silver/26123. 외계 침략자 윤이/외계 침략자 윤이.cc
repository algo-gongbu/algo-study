#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, D;
	cin >> N >> D;

	vector<int> heights(N);
	long long ans = 0;

	for (int n = 0; n < N; n++) {
		cin >> heights[n];
	}
	sort(heights.begin(), heights.end(), greater<>());
	
	int l = 0;
	for (int d = 0; d < D; d++) {
		int h = heights[l];
		while (l < N && (heights[l] == h)) {
			l++;
		}
		
		if (l == N) {
			ans += (long long)l * min((D - d), heights[l - 1]);
			break;
		}
		else {
			int diff = heights[l - 1] - heights[l];
			if (diff > (D - d)) {
				ans += ((long long)l * (D - d));
				break;
			}
			else {
				ans += ((long long)l * diff);
				d += (diff - 1);
			}
		}
	}
	cout << ans;

	return 0;
}