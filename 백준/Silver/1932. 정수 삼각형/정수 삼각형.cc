#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;
	vector<vector<int>> D(n + 2, vector<int>(n + 2, 0));

	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j < i; j++) {
			cin >> num;
			D[i][j] = D[i - 1][j - 1] < D[i - 1][j] ? D[i - 1][j] + num : D[i - 1][j - 1] + num;
		}
	}
	cout << *max_element(D[n + 1].begin(), D[n + 1].end()) << "\n";
	
	return 0;
}