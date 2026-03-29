#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, num, ans = -1;
	cin >> N;
	map<int, int> m;

	for (int i = 0; i < N; i++) {
		cin >> num;
		while (num % 2 == 0) {
			num /= 2;
		}
		m[num]++;
	}

	for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		ans = max(ans, iter->second);
	}

	cout << ans << '\n';

	return 0;
}