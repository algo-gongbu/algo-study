#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, W, H, N;
	cin >> T;
	
	while (T--) {
		cin >> H >> W >> N;
		if (N % H == 0) {
			cout << H * 100 + (N / H) << "\n";
		}
		else {
			cout << ((N % H) * 100) + (N / H) + 1 << "\n";
		}
	}
	return 0;
}