#include <bits/stdc++.h>

using namespace std;

#define ll long long

char board[8][7];
bool used[7][7], placed[8][7];
int cnt;

void f(int r) {
    if (r == 0) {++cnt; return;}

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!placed[i][j]) {
                int n1 = board[i][j] - '0';
                if (j + 1 < 7 && !placed[i][j + 1]) { 
                    int n2 = board[i][j + 1] - '0';
                    if (!used[min(n1, n2)][max(n1, n2)]) {
                        placed[i][j] = placed[i][j + 1] = true;
                        used[min(n1, n2)][max(n1, n2)] = true;
                        f(r - 1);
                        placed[i][j] = placed[i][j + 1] = false;
                        used[min(n1, n2)][max(n1, n2)] = false;
                    }
                }
                
                if (i + 1 < 8 && !placed[i + 1][j]) {
                    int n3 = board[i + 1][j] - '0';
                    if (!used[min(n1, n3)][max(n1, n3)]) {
                        placed[i][j] = placed[i + 1][j] = true;
                        used[min(n1, n3)][max(n1, n3)] = true;
                        f(r - 1);
                        placed[i][j] = placed[i + 1][j] = false;
                        used[min(n1, n3)][max(n1, n3)] = false;
                    }
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
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            cin >> board[i][j];
        }
    }

    f(28);

    cout << cnt << '\n';

    return 0;
}