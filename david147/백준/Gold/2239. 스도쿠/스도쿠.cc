#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char board[9][9];

void f(int cnt) {
    if (cnt == 0) {flag = true; return;}

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '0') {
                bool num[10];
                memset(num, true, sizeof(num));

                for (int k = 0; k < 9; k++) {
                    num[board[i][k] - '0'] = false;
                    num[board[k][j] - '0'] = false;
                }

                for (int y = 0; y < 3; y++) {
                    for (int x = 0; x < 3; x++) {
                        num[board[3 * (i / 3) + y][3 * (j / 3) + x] - '0'] = false;
                    }
                }

                for (int k = 1; k <= 9; k++) {
                    if (!num[k]) continue;
                    
                    board[i][j] = '0' + k;
                    f(cnt - 1);
                    if (flag) return;
                    board[i][j] = '0';
                }
                
                return;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == '0') m++;
        }
    }
    
    f(m);

    if (flag) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
    
    return 0;
}