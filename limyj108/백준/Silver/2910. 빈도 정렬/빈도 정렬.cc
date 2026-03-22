#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, C, x;
	cin >> N >> C;

	map<int, pii> m; 
	vector<pair<int, pii>> v;

	for (int n = 0; n < N; n++) {
		cin >> x;
		if (m[x].second == 0) {
			m[x].first = n;
		}
		m[x].second++;
	}

	for (map<int, pii>::iterator iter = m.begin(); iter != m.end(); iter++) {
		v.push_back({ iter->first, { iter->second.first, iter->second.second } });
	}

	sort(v.begin(), v.end(), [](const pair<int, pii>& a, const pair<int, pii>& b) {
		if (a.second.second > b.second.second)
			return true;
		else if (a.second.second < b.second.second)
			return false;
		else
			return a.second.first < b.second.first;
	});

	for (vector<pair<int, pii>>::iterator iter = v.begin(); iter != v.end(); iter++) {
		for (int i = 0; i < iter->second.second; i++) {
			cout << iter->first << " ";
		}
	}

	return 0;
}