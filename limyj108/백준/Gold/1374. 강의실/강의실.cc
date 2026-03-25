#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct lecture {
	int n;
	int s;
	int e;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, n, s, e;
	vector<lecture> lectures;
	priority_queue<int, vector<int>, greater<>> pq;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n >> s >> e;
		lectures.push_back({ n, s, e });
	}
	sort(lectures.begin(), lectures.end(), [](const lecture& a, const lecture& b) {
		return a.s < b.s;
	});

	for (int n = 0; n < N; n++) {
		if (pq.empty()) {
			pq.push(lectures[n].e);
		}
		else if (lectures[n].s >= pq.top()) {
			pq.pop();
			pq.push(lectures[n].e);
		}
		else {
			pq.push(lectures[n].e);
		}
	}
	cout << pq.size() << "\n";

	return 0;
}