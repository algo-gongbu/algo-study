#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), [](int& a, int& b) {
		return a > b;
	});
	
	for (int i = 1; i <= N; i++) {
		v[i - 1] = v[i - 1] *i;
	}
	cout << *max_element(v.begin(), v.end()) << "\n";

	return 0;
}