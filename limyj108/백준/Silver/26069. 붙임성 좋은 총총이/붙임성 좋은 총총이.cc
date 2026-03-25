#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	string A, B;
	set<string> s;

	cin >> N;
	s.insert("ChongChong");

	for (int n = 0; n < N; n++) {
		cin >> A >> B;
		if (s.find(A) != s.end()) {
			s.insert(B);
		}
		else if (s.find(B) != s.end()) {
			s.insert(A);
		}
	}
	cout << s.size() << "\n";

	return 0;
}