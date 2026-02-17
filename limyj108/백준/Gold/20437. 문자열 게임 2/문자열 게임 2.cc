#include <iostream>
#include <string>
#include <vector>
#include <map>
#define MIN 0
#define MAX 10001

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, k;
	string w;
	cin >> T;

	while (T--) {
		cin >> w >> k;
		int w_size = (int) w.size();
		int min_len = MAX, max_len = MIN;
		map<char, vector<int>> m;

		for (int i = 0; i < w_size; i++) {
			m[w[i]].push_back(i);
		}

		for (map<char, vector<int>>::iterator iter = m.begin(); iter != m.end(); iter++) {
			int num = iter->second.size();
			if (num < k)
				continue;

			for (int j = 0; j + k - 1 < num; j++) {
				int dist = iter->second[j + k - 1] - iter->second[j] + 1;
				min_len = dist < min_len ? dist : min_len;
				max_len = dist > max_len ? dist : max_len;
			}			
		}

		if (min_len == MAX) {
			cout << -1 << "\n";
		}
		else {
			cout << min_len << " " << max_len << "\n";
		}
	}

	return 0;
}