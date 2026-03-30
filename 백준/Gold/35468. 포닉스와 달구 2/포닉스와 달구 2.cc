#include <iostream>
#include <vector>

using namespace std;

int N, n = 0;
int zz = 0, zo = 0, oo = 0;
vector<int> board;

void count_board() {
	int cnt = 0;
	for (int i = 0; i < (N / 2); i++) {
		if (board[i] != board[N - 1 - i]) {
			zo++;
		}
		else {
			if (board[i] == 0) {
				zz++;
			}
			else {
				oo++;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	board.resize(N);
	bool flag = true;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
		if (board[i] == 1) {
			n++;
		}
	}
	count_board();

	if (zo >= 3) {
		cout << "PONIX";
	}
	else if (zo == 2) {
		if (N % 2 == 1 && board[N / 2] == 0) {
			cout << "PONIX";
		}
		else {
			if (zz > 0) {
				cout << "PONIX";
			}
			else {
				cout << "DALGU";
			}
		}
	}
	else if (zo == 1) {
		if (n + 1 == N) {
			cout << "DALGU";
		}
		else if (N % 2 == 1 && board[N / 2] == 0) {
			cout << "DALGU";
		}	
		else {
			cout << "PONIX";
		}
	}
	else { // zo == 0
		if (n + 1 == N) {
			cout << "DALGU";
		}
		else if (N % 2 == 1 && board[N / 2] == 0) {
			cout << "PONIX";
		}
		else {
			cout << "DALGU";
		}
	}

	return 0;
}