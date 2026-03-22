#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, num;
	cin >> N;
	priority_queue<int, vector<int>, greater<>> pq;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> num;
			pq.push(num);

			if (pq.size() > N) {
				pq.pop();
			}
		}
	}
	cout << pq.top() << "\n";

	return 0;
}