#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int b_acc[2001][2001], w_acc[2001][2001];
char board[2001][2001];

void f() {
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i + j) % 2 == 0) {
                if (board[i][j] == 'W') {
                    b_acc[i][j] = b_acc[i - 1][j] + b_acc[i][j - 1] - b_acc[i - 1][j - 1] + 1;
                    w_acc[i][j] = w_acc[i - 1][j] + w_acc[i][j - 1] - w_acc[i - 1][j - 1];
                }
                else {
                    b_acc[i][j] = b_acc[i - 1][j] + b_acc[i][j - 1] - b_acc[i - 1][j - 1];
                    w_acc[i][j] = w_acc[i - 1][j] + w_acc[i][j - 1] - w_acc[i - 1][j - 1] + 1;
                }
            }
            else {
                if (board[i][j] == 'B') {
                    b_acc[i][j] = b_acc[i - 1][j] + b_acc[i][j - 1] - b_acc[i - 1][j - 1] + 1;
                    w_acc[i][j] = w_acc[i - 1][j] + w_acc[i][j - 1] - w_acc[i - 1][j - 1];
                }
                else {
                    b_acc[i][j] = b_acc[i - 1][j] + b_acc[i][j - 1] - b_acc[i - 1][j - 1];
                    w_acc[i][j] = w_acc[i - 1][j] + w_acc[i][j - 1] - w_acc[i - 1][j - 1] + 1;
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << b_acc[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << w_acc[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int b_ans, w_ans;
    for (int i = h; i <= n; i++) {
        for (int j = h; j <= m; j++) {
            b_ans = b_acc[i][j] - b_acc[i - h][j] - b_acc[i][j - h] + b_acc[i - h][j - h]; 
            w_ans = w_acc[i][j] - w_acc[i - h][j] - w_acc[i][j - h] + w_acc[i - h][j - h];
            if (minimum > min(b_ans, w_ans)) minimum = min(b_ans, w_ans);
        }
    }

    cout << minimum << '\n';

    return 0;
}