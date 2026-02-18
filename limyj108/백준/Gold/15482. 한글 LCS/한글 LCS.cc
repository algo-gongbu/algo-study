#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
    
	int s1_size = s1.size() / 3;
    int s2_size = s2.size() / 3;
	vector<vector<int>> D(s1_size + 1, vector<int>(s2_size + 1, 0));

	for (int r = 1; r <= s1_size; r++) {
		for (int c = 1; c <= s2_size; c++) {
			if (s1[(r - 1) * 3] == s2[(c - 1) * 3] && s1[(r - 1) * 3 + 1] == s2[(c - 1) * 3 + 1] && s1[(r - 1) * 3 + 2] == s2[(c - 1) * 3 + 2]) {
				D[r][c] = D[r - 1][c - 1] + 1;
			}
			else {
				D[r][c] = max(D[r - 1][c], D[r][c - 1]);
			}
		}
	}
    
	cout << D[s1_size][s2_size];

	return 0;
}