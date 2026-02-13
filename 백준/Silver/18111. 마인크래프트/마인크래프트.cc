#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, inv;
    cin >> r >> c >> inv;

    vector<vector<int>> board(r, vector<int>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    int bestT = INT_MAX;
    int bestH = 0;

    for (int h = 0; h <= 256; h++) {
        int time = 0;
        int curInv = inv;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                int diff = board[i][j] - h;

                if (diff > 0) {          // 제거
                    time += diff * 2;
                    curInv += diff;
                }
                else {                   // 쌓기
                    time += -diff;
                    curInv += diff;      // diff는 음수
                }
            }
        }

        if (curInv >= 0) {
            if (time < bestT || (time == bestT && h > bestH)) {
                bestT = time;
                bestH = h;
            }
        }
    }

    cout << bestT << " " << bestH;
}
