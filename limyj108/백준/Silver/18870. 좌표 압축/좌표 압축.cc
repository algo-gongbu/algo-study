#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	cin >> N;
	vector<pii> v;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back({i, num}); // <index, number>
	}

	sort(v.begin(), v.end(), [](pii a, pii b) {
		return a.second < b.second;
	});

	int pre = v[0].second, cnt = 0;
	v[0].second = cnt;

	for (int i = 1; i < N; i++) {
		if (pre != v[i].second)
			cnt++;
		pre = v[i].second;
		v[i].second = cnt;
	}

	sort(v.begin(), v.end(), [](pii a, pii b) {
		return a.first < b.first;
	});

	for (int i = 0; i < N; i++) {
		cout << v[i].second << " ";;
	}
	
	return 0;
}